#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include "./Track.h"
#include <QStringListModel>
#include <QObject>
#include <QVector>
#include <QFile>
#include <QTextStream>

class TrackModel : public QStringListModel{
Q_OBJECT
private:
    QVector<Track*> tracks;
    int total_races;

protected:
    //QModelIndexList match(const QModelIndex&, int, const QVariant&, int = 1, Qt::MatchFlags = Qt::MatchStartsWith) const override;

public:
    explicit TrackModel(QString, QObject *parent = nullptr);
    ~TrackModel();
    //int rowCount(const QModelIndex&) const override;
    //QVariant data(const QModelIndex&, int) const override;

    // 2 different versions of finders
    Track* get_track_by_code(QString) const;
    Track* get_track_by_verbose(QString) const;
    Track* get_track_by_input(QString) const;
    Track* get_track_by_id(int) const;

    // Getter to retrieve all tracks
    QVector<Track*> get_tracks() const;

    // Function to add placement to specified track
    void add_placement_to_track(int, int);
    Track* get_best_track() const;
    Track* get_worst_track() const;
    int get_total_races() const;
};

#endif // TRACKMODEL_H
