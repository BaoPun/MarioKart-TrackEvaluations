#include "./Track.h"

Track::Track(QString verbose, QString abbreviation, int id, QString origin) : id(id){
    this->verbose = verbose;
    this->abbreviation = abbreviation;
    this->origin = origin;
}

/**
 * @brief Simply returns the track name w/o the course's game of origin.
 * @return
 */
QString Track::get_course_name() const{
    return this->verbose;
}

/**
 * @brief Grabs the entire course name with its game of origin (i.e. GCN Baby Park)
 * @return
 */
QString Track::get_verbose() const{
    return this->origin == "" ? this->verbose : this->origin + " " + this->verbose;
}

/**
 * @brief Returns the track code corresponding to the track.  Ex: Mario Kart Stadium would return MKS.
 * @return
 */
QString Track::get_abbreviation() const{
    return this->abbreviation;
}

/**
 * @brief Returns the unique ID of the track
 * @return id
 */
int Track::get_id() const{
    return this->id;
}

/**
 * @brief If the placement input was between 1 and 12, add it to the rolling sum and store the placement itself.
 * @param placement - placement # between 1 and 12.
 */
void Track::add_placement(int placement){
    if(placement >= 1 && placement <= 12){
        this->placements.push_back(placement);
        this->placement_sum += placement;
    }
}

/**
 * @brief Return the average of all placements, but return 0 instead if no placements were inputted.
 * @return
 */
double Track::get_average_placement() const{
    return this->placements.isEmpty() ? 0 : this->placement_sum * 1.0 / this->placements.size();
}

/**
 * @brief Return all placements (mainly used for generating a bar graph using this data)
 * @return a list of all placements
 */
QVector<int> Track::get_all_placements(){
    return this->placements;
}

