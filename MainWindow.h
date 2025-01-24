#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./TrackModel.h"
#include <QMainWindow>
#include <QCompleter>
#include <QKeyEvent>
#include <QLabel>
#include <QLayout>
#include <QtCharts>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
Q_OBJECT
private:
    Ui::MainWindow *ui;
    TrackModel* tracks;

    // Store the current label
    QLabel* track_image;
    QChartView* line_graph;

    // Store a bar graph of all the different placements
    QChartView* bar_graph;

    bool track_selected_dropdown = false;

    bool eventFilter(QObject*, QEvent*) override;

    // Helper functions
    void process_track_input();
    void load_image(Track*);
    void load_graph(Track*);
    void save_configuration();
    void add_placement_to_track();
    void update_overall_info();
    //void show_frequency_graph();

    int track_nbr = -1;

protected:
    void closeEvent(QCloseEvent*) override;

private slots:
    //void search_changed(QString);
    void selected_track(/*QModelIndex*/);
    void show_frequency_graph();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


};
#endif // MAINWINDOW_H
