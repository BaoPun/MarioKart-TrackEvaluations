#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    this->ui->setupUi(this);

    // Change title
    this->setWindowTitle("Mario Kart 8 Deluxe: Track Performance Monitor");
    this->setFixedSize(800, 650);

    // Create the track model
    this->tracks = new TrackModel("./tracks_save_data.mk8d", this);

    // No image, initially
    this->track_image = nullptr;
    this->line_graph = nullptr;

    // Initially, hide the score input
    this->ui->score_input->setVisible(false);
    this->ui->track_info->setVisible(false);

    // Hide scrollbars from text browser
    this->ui->overall_info->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->overall_info->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create the track listing
    QStringList matches;
    for(size_t i = 0; i < this->tracks->get_tracks().size(); i++)
        matches.append(this->tracks->get_tracks().at(i)->get_verbose() + "\t" + this->tracks->get_tracks().at(i)->get_abbreviation());
    this->tracks->setStringList(std::move(matches));

    // Programmatically add dropdown options to the search bar
    QCompleter* completer = new QCompleter(this->tracks, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    this->ui->track_search_bar->setCompleter(completer);

    // Center all widgets in the frame
    this->ui->data_layout->setAlignment(Qt::AlignCenter);

    // For the overall track info, always show the best and worst
    this->update_overall_info();

    // When we press enter on the completer, set to readonly
    this->connect(this->ui->track_search_bar->completer(), SIGNAL(activated(QString)), this, SLOT(selected_track()), Qt::QueuedConnection);

    // Install custom event filters
    this->ui->centralwidget->installEventFilter(this);
    this->ui->track_search_bar->installEventFilter(this);
    this->ui->score_input->installEventFilter(this);
}

MainWindow::~MainWindow(){
    if(this->line_graph != nullptr){
        delete this->line_graph;
        this->line_graph = nullptr;
    }
    if(this->track_image != nullptr){
        delete this->track_image;
        this->track_image = nullptr;
    }
    if(this->tracks != nullptr){
        delete this->tracks;
        this->tracks = nullptr;
    }
    if(this->ui != nullptr){
        delete this->ui;
        this->ui = nullptr;
    }
}

/**
 * @brief Helper function to load the found image after search
 * @param found_track - Track pointer that points to details of the found track
 */
void MainWindow::load_image(Track* found_track){
    QImage image("./MK8D_Tracks/" + found_track->get_abbreviation() + ".png");
    if(this->track_image != nullptr){
        this->ui->data_layout->removeWidget(this->track_image);
        delete this->track_image;
    }
    this->track_image = new QLabel();
    this->track_image->setPixmap(QPixmap::fromImage(image));
    this->ui->data_layout->addWidget(this->track_image);
    this->ui->data_layout->setAlignment(this->track_image, Qt::AlignCenter);

    // Also show the score input
    this->ui->score_input->setVisible(true);

    // Also store the current index #.  Subtract by 1 to get the 0-based index #.
    this->track_nbr = found_track->get_id() - 1;
}

/**
 * @brief Helper function to load the graph of all placements after each search
 * @param found_track - Track pointer that points to details of the found track
 */
void MainWindow::load_graph(Track* found_track){
    if(this->line_graph != nullptr){
        this->ui->data_layout->removeWidget(this->line_graph);
        delete this->line_graph->chart();
        delete this->line_graph;
    }

    // Create a chart along with the chart view (we handle the chart view)
    QChart* chart = new QChart();
    this->line_graph = new QChartView(chart);

    // Then, create the QLineSeries, where the chart will contain the line series
    QLineSeries* line_series = new QLineSeries();
    line_series->append(0, 12);
    QVector<int> placements = this->tracks->get_tracks().at(this->track_nbr)->get_all_placements();
    for(size_t i = 0; i < placements.size(); i++){
        line_series->append(i+1, placements.at(i));
    }
    line_series->setPointsVisible(true);
    chart->setTitle("Scores for " + found_track->get_verbose());
    chart->addSeries(line_series);



    // Add axes manually
    QValueAxis* x_axis = new QValueAxis();
    QValueAxis* y_axis = new QValueAxis();
    x_axis->setTitleText("Race #");
    x_axis->setRange(0, placements.size() + 1);
    x_axis->setMin(0);
    if(placements.size() > 1)
        x_axis->setMin(1);
    y_axis->setTitleText("Placements (1-12)");
    y_axis->setTickCount(7);
    y_axis->setReverse(true);
    chart->addAxis(x_axis, Qt::AlignBottom);
    line_series->attachAxis(x_axis);
    y_axis->setRange(0, 12);
    chart->addAxis(y_axis, Qt::AlignLeft);
    line_series->attachAxis(y_axis);
    chart->legend()->hide();

    this->line_graph->setRenderHint(QPainter::Antialiasing);
    this->ui->data_layout->addWidget(this->line_graph);

    // Update the track_info display
    this->ui->track_info->setVisible(true);
    this->ui->track_info->setText(this->tracks->get_track_by_id(this->track_nbr)->get_verbose()
                                  + "\n\n\nTotal races: " + QString::number(placements.size())
                                  + "\nAverage placement: " + QString::number(this->tracks->get_track_by_id(this->track_nbr)->get_average_placement())
    );
}

/**
 * @brief After pressing ENTER, process the input, by loading the track image
 * @param input
 */
void MainWindow::process_track_input(){
    // First, ensure that the search input results in a valid track.
    // If the track was selected via dropdown, then this is ALWAYS valid.
    Track* found_track = nullptr;
    if(this->track_selected_dropdown){
        // Before finding the track, splice by the "\t" character
        int idx = this->ui->track_search_bar->text().toStdString().find('\t') + 1;
        found_track = this->tracks->get_track_by_input(QString::fromStdString(this->ui->track_search_bar->text().toStdString().substr(idx)));
        qDebug() << "Placement average:" << found_track->get_average_placement();

        // Find corresponding image from found track and load it into the frame. (via course code)
        this->load_image(found_track);
        this->load_graph(found_track);

    }
    else{
        found_track = this->tracks->get_track_by_input(this->ui->track_search_bar->text());
        if(found_track != nullptr){
            qDebug() << "Placement average:" << found_track->get_average_placement();

            // Find corresponding image from found track and load it into the frame. (via course code)
            this->load_image(found_track);
            this->load_graph(found_track);
        }
        else{
            qDebug() << "Error, track not found...";
        }
    }

    // Lastly, trigger the selected flag to be false again, and reset the search bar
    this->track_selected_dropdown = false;
    this->ui->track_search_bar->clear();
    this->ui->track_search_bar->setReadOnly(false);
}

/**
 * @brief After selecting the track from the dropdown, set the text field to readonly.
 * @param index
 */
void MainWindow::selected_track(){
    //qDebug() << "Pressed enter, slot triggered.  Input =" << this->ui->track_search_bar->text() << ", index=" << index;

    // Do not allow additional input
    this->ui->track_search_bar->setReadOnly(true);

    // Trigger this flag to be true, as we have selected the track via dropdown
    this->track_selected_dropdown = true;

    // TODO: load both image and graph
    this->process_track_input();
    this->update_overall_info();
    this->ui->score_input->setFocus();
}

/**
 * @brief Prior to quitting, this function will save ALL placement inputs
 */
void MainWindow::save_configuration(){
    QFile output_file("./tracks_save_data.mk8d");
    output_file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream fout(&output_file);
    for(size_t i = 0; i < this->tracks->get_tracks().size(); i++){
        // Each line: code,# of placements, each placement
        QVector<int> placements = this->tracks->get_tracks().at(i)->get_all_placements();
        fout << this->tracks->get_tracks().at(i)->get_abbreviation() << "," << placements.size();
        if(placements.size() > 0){
            fout << ",";
            for(size_t j = 0; j < placements.size(); j++){
                fout << placements.at(j);
                if(j != placements.size() - 1)
                    fout << ",";
            }
        }
        fout << Qt::endl;
    }

    output_file.close();
}

/**
 * @brief After submitting the track, attempt to add the place number to the specified track.
 */
void MainWindow::add_placement_to_track(){
    // First we have to validate the input: numerical and between 1 and 12
    bool is_numeric;
    int placement = this->ui->score_input->text().toInt(&is_numeric);
    if(is_numeric && placement >= 1 && placement <= 12){
        this->tracks->add_placement_to_track(this->track_nbr, placement);
        qDebug() << "Successfully added placement.";

        // And update the track
        this->load_graph(this->tracks->get_track_by_id(this->track_nbr));
    }
}

/**
 * @brief Updates overall info, display best and worst tracks based on average
 */
void MainWindow::update_overall_info(){
    Track* best = this->tracks->get_best_track();
    Track* worst = this->tracks->get_worst_track();
    Track* mode = this->tracks->get_most_played_track();

    // Update the overall info
    if(best == nullptr || worst == nullptr)
        this->ui->overall_info->setText("No data.");
    else
        this->ui->overall_info->setText("Best track: " + best->get_verbose() +
                                        "\nWorst track: " + worst->get_verbose() +
                                        "\n\nMost played:\n" + (mode == nullptr ? "No data" : mode->get_verbose() + " (" + QString::number(mode->get_all_placements().size()) + " times)") +
                                        "\n\nTotal races: " + QString::number(this->tracks->get_total_races())
                                    );
}

/**
 * @brief Manually handle specific key events
 * @param object
 * @param event
 * @return
 */
bool MainWindow::eventFilter(QObject* object, QEvent* event){
    // Pressing any key
    if(event->type() == QEvent::KeyPress){
        // If we pressed enter and the object was the search bar
        // TODO: Process it and then clear input
        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);

        if(object == this->ui->track_search_bar && key_event->key() == Qt::Key_Return){
            qDebug() << "Pressed enter.  Input =" << this->ui->track_search_bar->text();

            // Send to a helper function.
            this->process_track_input();
            this->update_overall_info();
            this->ui->score_input->setFocus();

            return true;
        }

        // Pressing enter on the score input will also reset it
        else if(object == this->ui->score_input && key_event->key() == Qt::Key_Return){
            // TODO: process the score via helper function.
            this->add_placement_to_track();
            this->update_overall_info();

            // Clear the score
            this->ui->score_input->clear();

            // And set focus to the track selection
            this->ui->track_search_bar->setFocus();

            return true;
        }

        // CTRL Q = quits the program altogether.
        else if(object == this->ui->centralwidget && key_event->key() == Qt::Key_Q && (key_event->modifiers() & Qt::ControlModifier)){
            // Before closing, save all inputs (moved to closeEvent)
            //this->save_configuration();

            this->close();
            return true;
        }

        // Pressing tab will change focus
        else if(key_event->key() == Qt::Key_Tab){
            // If the search bar is currently in focus, bring focus to the placement input
            // Or vice-versa
            if(object == this->ui->score_input)
                this->ui->track_search_bar->setFocus();
            else if(object == this->ui->track_search_bar){
                if(this->ui->score_input->isVisible()){
                    this->ui->score_input->setFocus();
                    return true;
                }
                return false;
            }
            return true;
        }

    }

    return false;
}

/**
 * @brief Prior to closing the entire window, save the current configuration
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent* event){
    // Before accepting the event, save the current configuration
    this->save_configuration();
    event->accept();
}
