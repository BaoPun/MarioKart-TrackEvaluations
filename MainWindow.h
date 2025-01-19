#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./TrackModel.h"
#include <QMainWindow>
#include <QCompleter>
#include <QKeyEvent>
#include <QLabel>
#include <QLayout>
#include <QtCharts>

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
    //TrackSearchModel* proxy;
    QChartView* line_graph;

    // Store the current label
    QLabel* track_image;

    bool track_selected_dropdown = false;

    bool eventFilter(QObject*, QEvent*) override;

    // Helper functions
    void process_track_input();
    void load_image(Track*);
    void load_graph(Track*);
    void save_configuration();
    void add_placement_to_track();
    void update_overall_info();

    int track_nbr = -1;

protected:
    void closeEvent(QCloseEvent*) override;

private slots:
    //void search_changed(QString);
    void selected_track(/*QModelIndex*/);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


};
#endif // MAINWINDOW_H
