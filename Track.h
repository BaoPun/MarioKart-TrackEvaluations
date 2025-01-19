#ifndef TRACK_H
#define TRACK_H

#include <QObject>
#include <QVector>

class Track : public QObject
{
private:
    QString verbose;
    QString abbreviation;
    QString origin;

    // Store unique ID (ones-based)
    const int id;

    // Also store data for each placement result
    QVector<int> placements;
    int placement_sum = 0;

public:
    Track(QString, QString, int, QString = "");

    QString get_course_name() const;
    QString get_verbose() const;
    QString get_abbreviation() const;
    int get_id() const;

    // Functions to help graph placement results + average
    void add_placement(int);
    double get_average_placement() const;
    QVector<int> get_all_placements();
};


#endif // TRACK_H
