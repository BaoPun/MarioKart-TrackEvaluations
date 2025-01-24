#include "TrackModel.h"

TrackModel::TrackModel(QString file, QObject *parent) : QStringListModel(parent), total_races(0){
    // Initialize all 96 tracks
    int id = 1;
    this->tracks.push_back(new Track("Mario Kart Stadium","MKS", id++));
    this->tracks.push_back(new Track("Water Park","WP", id++));
    this->tracks.push_back(new Track("Sweet Sweet Canyon","SSC", id++));
    this->tracks.push_back(new Track("Thwomp Ruins","TR", id++));
    this->tracks.push_back(new Track("Mario Circuit","MC", id++));
    this->tracks.push_back(new Track("Toad Harbor","TH", id++));
    this->tracks.push_back(new Track("Twisted Mansion","TM", id++));
    this->tracks.push_back(new Track("Shy Guy Falls","SGF", id++));
    this->tracks.push_back(new Track("Sunshine Airport","SA", id++));
    this->tracks.push_back(new Track("Dolphin Shoals","DS", id++));
    this->tracks.push_back(new Track("Electrodrome","Ed", id++));
    this->tracks.push_back(new Track("Mount Wario","MW", id++));
    this->tracks.push_back(new Track("Cloudtop Cruise","CC", id++));
    this->tracks.push_back(new Track("Bone-Dry Dunes","BDD", id++));
    this->tracks.push_back(new Track("Bowser's Castle","BC", id++));
    this->tracks.push_back(new Track("Rainbow Road","RR", id++));
    this->tracks.push_back(new Track("Moo Moo Meadows","rMMM", id++, "Wii"));
    this->tracks.push_back(new Track("Mario Circuit","rMC", id++, "GBA"));
    this->tracks.push_back(new Track("Cheep Cheep Beach","rCCB", id++, "DS"));
    this->tracks.push_back(new Track("Toad's Turnpike","rTT", id++,"N64"));
    this->tracks.push_back(new Track("Dry Dry Desert","rDDD", id++,"GCN"));
    this->tracks.push_back(new Track("Donut Plains 3","rDP3", id++,"SNES"));
    this->tracks.push_back(new Track("Royal Raceway","rRRy", id++,"N64"));
    this->tracks.push_back(new Track("DK Jungle","rDKJ", id++,"3DS"));
    this->tracks.push_back(new Track("Wario Stadium","rWS", id++,"DS"));
    this->tracks.push_back(new Track("Sherbet Land","rSL", id++,"GCN"));
    this->tracks.push_back(new Track("Music Park","rMP", id++,"3DS"));
    this->tracks.push_back(new Track("Yoshi Valley","rYV", id++,"N64"));
    this->tracks.push_back(new Track("Tick-Tock Clock","rTTC", id++,"DS"));
    this->tracks.push_back(new Track("Piranha Plant Slide","rPPS", id++,"3DS"));
    this->tracks.push_back(new Track("Grumble Volcano","rGV", id++,"Wii"));
    this->tracks.push_back(new Track("Rainbow Road","rRRd", id++,"N64"));
    this->tracks.push_back(new Track("Yoshi Circuit","dYC", id++,"GCN"));
    this->tracks.push_back(new Track("Excitebike Arena","dEA", id++));
    this->tracks.push_back(new Track("Dragon Driftway","dDD", id++));
    this->tracks.push_back(new Track("Mute City","dMC", id++));
    this->tracks.push_back(new Track("Wario's Gold Mine","dWGM", id++,"Wii"));
    this->tracks.push_back(new Track("Rainbow Road","dRR", id++,"SNES"));
    this->tracks.push_back(new Track("Ice Ice Outpost","dIIO", id++));
    this->tracks.push_back(new Track("Hyrule Circuit","dHC", id++));
    this->tracks.push_back(new Track("Baby Park","dBP", id++,"GCN"));
    this->tracks.push_back(new Track("Cheese Land","dCL", id++,"GBA"));
    this->tracks.push_back(new Track("Wild Woods","dWW", id++));
    this->tracks.push_back(new Track("Animal Crossing","dAC", id++));
    this->tracks.push_back(new Track("Neo Bowser City","dNBC", id++,"3DS"));
    this->tracks.push_back(new Track("Ribbon Road","dRiR", id++,"GBA"));
    this->tracks.push_back(new Track("Super Bell Subway","dSBS", id++));
    this->tracks.push_back(new Track("Big Blue","dBB", id++));
    this->tracks.push_back(new Track("Paris Promenade","bPP", id++,"Tour"));
    this->tracks.push_back(new Track("Toad Circuit","bTC", id++,"3DS"));
    this->tracks.push_back(new Track("Choco Mountain","bCMo", id++,"N64"));
    this->tracks.push_back(new Track("Coconut Mall","bCMa", id++,"Wii"));
    this->tracks.push_back(new Track("Tokyo Blur","bTB", id++,"Tour"));
    this->tracks.push_back(new Track("Shroom Ridge","bSR", id++,"DS"));
    this->tracks.push_back(new Track("Sky Garden","bSG", id++,"GBA"));
    this->tracks.push_back(new Track("Ninja Hideaway","bNH", id++));
    this->tracks.push_back(new Track("New York Minute","bNYM", id++,"Tour"));
    this->tracks.push_back(new Track("Mario Circuit 3","bMC3", id++,"SNES"));
    this->tracks.push_back(new Track("Kalimari Desert","bKD", id++,"N64"));
    this->tracks.push_back(new Track("Waluigi Pinball","bWP", id++,"DS"));
    this->tracks.push_back(new Track("Sydney Sprint","bSS", id++,"Tour"));
    this->tracks.push_back(new Track("Snow Land","bSL", id++,"GBA"));
    this->tracks.push_back(new Track("Mushroom Gorge","bMG", id++,"Wii"));
    this->tracks.push_back(new Track("Sky-High Sundae","bSHS", id++));
    this->tracks.push_back(new Track("London Loop","bLL", id++,"Tour"));
    this->tracks.push_back(new Track("Boo Lake","bBL", id++,"GBA"));
    this->tracks.push_back(new Track("Rock Rock Mountain","bRRM", id++,"3DS"));
    this->tracks.push_back(new Track("Maple Treeway","bMT", id++,"Wii"));
    this->tracks.push_back(new Track("Berlin Byways","bBB", id++,"Tour"));
    this->tracks.push_back(new Track("Peach Gardens","bPG", id++,"DS"));
    this->tracks.push_back(new Track("Merry Mountain","bMM", id++));
    this->tracks.push_back(new Track("Rainbow Road","bRR7", id++,"3DS"));
    this->tracks.push_back(new Track("Amsterdam Drift","bAD", id++,"Tour"));
    this->tracks.push_back(new Track("Riverside Park","bRP", id++,"GBA"));
    this->tracks.push_back(new Track("DK Summit","bDKS", id++,"Wii"));
    this->tracks.push_back(new Track("Yoshi's Island","bYI", id++));
    this->tracks.push_back(new Track("Bangkok Rush","bBR", id++,"Tour"));
    this->tracks.push_back(new Track("Mario Circuit","bMC", id++,"DS"));
    this->tracks.push_back(new Track("Waluigi Stadium","bWS", id++,"GCN"));
    this->tracks.push_back(new Track("Singapore Speedway","bSSy", id++,"Tour"));
    this->tracks.push_back(new Track("Athens Dash","bAtD", id++,"Tour"));
    this->tracks.push_back(new Track("Daisy Cruiser","bDC", id++,"GCN"));
    this->tracks.push_back(new Track("Moonview Highway","bMH", id++,"Wii"));
    this->tracks.push_back(new Track("Squeaky Clean Sprint","bSCS", id++));
    this->tracks.push_back(new Track("Los Angeles Laps","bLAL", id++,"Tour"));
    this->tracks.push_back(new Track("Sunset Wilds","bSW", id++,"GBA"));
    this->tracks.push_back(new Track("Koopa Cape","bKC", id++,"Wii"));
    this->tracks.push_back(new Track("Vancouver Velocity","bVV", id++,"Tour"));
    this->tracks.push_back(new Track("Rome Avanti","bRA", id++,"Tour"));
    this->tracks.push_back(new Track("DK Mountain","bDKM", id++,"GCN"));
    this->tracks.push_back(new Track("Daisy Circuit","bDCt", id++,"Wii"));
    this->tracks.push_back(new Track("Piranha Plant Cove","bPPC", id++));
    this->tracks.push_back(new Track("Madrid Drive","bMD", id++,"Tour"));
    this->tracks.push_back(new Track("Rosalina's Ice World", "bRIW",id++,"3DS"));
    this->tracks.push_back(new Track("Bowser Castle 3","bBC3", id++,"SNES"));
    this->tracks.push_back(new Track("Rainbow Road","bRRW", id++,"Wii"));

    // Run a loop through all 96 tracks and read the file
    QFile input_file(file);
    if(!input_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        input_file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream fout(&input_file);
        for(size_t i = 0; i < this->tracks.size(); i++)
            fout << this->tracks.at(i)->get_abbreviation() << ",0" << Qt::endl;
        input_file.close();
    }
    QTextStream fin(&input_file);
    for(size_t i = 0; i < this->tracks.size(); i++){
        QString line;
        fin >> line;

        // Each part of a line consists of [code, N (# of placements entered), N remaining placements]
        QStringList line_components = line.split(',');
        for(size_t j = 2; j < line_components.size(); j++){
            this->add_placement_to_track(i, line_components.at(j).toInt());
        }
    }

    // Make sure to close the file afterwards.
    input_file.close();
}

TrackModel::~TrackModel(){
    for(size_t i = 0; i < this->tracks.size(); i++)
        delete this->tracks.at(i);
}

/*int TrackModel::rowCount(const QModelIndex& parent) const{
    return this->tracks.size();
}*/


/*QVariant TrackModel::data(const QModelIndex& index, int role) const{
    if(index.isValid()){
        if(role == Qt::EditRole || role == Qt::DisplayRole){
            return this->tracks.at(index.row())->get_verbose();
        }
    }

    return QVariant();
}*/

QVector<Track*> TrackModel::get_tracks() const{
    return this->tracks;
}

/**
 * @brief Given a string as input, return the corresponding track (either verbose or abbrev).
 *        Otherwise, return a nullptr.  However, if the track has multiple verboses, then return nullptr instead.
 * @param input - string input from the search bar.
 * @return Track* - the found track or a nullptr otherwise.
 */
Track* TrackModel::get_track_by_input(QString input) const{
    Track* found_track = nullptr;
    for(size_t i = 0; i < this->tracks.size(); i++){
        if(this->tracks.at(i)->get_abbreviation().toLower() == input.toLower())
            return this->tracks.at(i);
        else if(this->tracks.at(i)->get_verbose().toLower() == input.toLower())
            return this->tracks.at(i);
        else if(this->tracks.at(i)->get_course_name().toLower() == input.toLower()){
            if(found_track == nullptr)
                found_track = this->tracks.at(i);
            else{
                qDebug() << "Please refine your search...  Returning nullptr";
                return nullptr;
            }
        }
    }
    return found_track;
}

/**
 * @brief Given the track index, return the corresponding track.  But if index is invalid, return nullptr instead.
 * @return idx -> index of track to retrieve
 */
Track* TrackModel::get_track_by_id(int idx) const{
    return (idx < 0 || idx >= this->tracks.size()) ? nullptr : this->tracks.at(idx);
}

/**
 * @brief Given the index of a track, add its placement results to that track.
 * @param track_idx - index of the track
 * @param placement - track score
 */
void TrackModel::add_placement_to_track(int track_idx, int placement){
    this->tracks.at(track_idx)->add_placement(placement);
    ++this->total_races;
}

/**
 * @brief Returns the best performing track, determined by the lowest average placement.
 * But, tracks with larger sample sizes with slightly lower average than tracks with smaller samples will take priority by a factor of +- 0.25.
 * @return a pointer to the best track, or null if all tracks' averages are 0.
 */
Track* TrackModel::get_best_track() const{
    Track* best = nullptr;
    double best_score = -1;

    for(size_t i = 0; i < this->tracks.size(); i++){
        if(this->tracks.at(i)->get_average_placement() != 0){
            if(best == nullptr){
                best = this->tracks.at(i);
                best_score = this->tracks.at(i)->get_average_placement();
            }
            else if((this->tracks.at(i)->get_all_placements().size() > best->get_all_placements().size() && this->tracks.at(i)->get_average_placement() - best_score <= 0.5) || best_score > this->tracks.at(i)->get_average_placement()){
                best = this->tracks.at(i);
                best_score = this->tracks.at(i)->get_average_placement();
            }
        }
    }

    return best;
}

/**
 * @brief Returns the worst performing track, determined by the highest average placement.
 * But, tracks with larger sample sizes with slightly higher average than tracks with smaller samples will take priority by a factor of +- 0.5.
 * @return a pointer to the worst track, or null if all tracks' averages are 0.
 */
Track* TrackModel::get_worst_track() const{
    Track* worst = nullptr;
    double worst_score = 100;

    for(size_t i = 0; i < this->tracks.size(); i++){
        if(this->tracks.at(i)->get_average_placement() != 0){
            if(worst == nullptr){
                worst = this->tracks.at(i);
                worst_score = this->tracks.at(i)->get_average_placement();
            }
            else if((this->tracks.at(i)->get_all_placements().size() > worst->get_all_placements().size() && worst_score - this->tracks.at(i)->get_average_placement() <= 0.5) || worst_score < this->tracks.at(i)->get_average_placement()){
                worst = this->tracks.at(i);
                worst_score = this->tracks.at(i)->get_average_placement();
            }
        }
    }

    return worst;
}

/**
 * @brief Returns the total # of races for all 96 tracks.
 * @return sum of all races.
 */
int TrackModel::get_total_races() const{
    return this->total_races;
}

/**
 * @brief Returns the track that is most played, or null if none of the tracks have been played.
 * @return track that is most played, or nullptr if none have been played at all.
 */
Track* TrackModel::get_most_played_track() const{
    Track* most_played = this->tracks.at(0);
    int most_played_count = most_played->get_all_placements().size();

    for(size_t i = 1; i < this->tracks.size(); i++){
        if(most_played_count < this->tracks.at(i)->get_all_placements().size()){
            most_played = this->tracks.at(i);
            most_played_count = most_played->get_all_placements().size();
        }
    }

    return (most_played_count > 0 ? most_played : nullptr);
}

/**
 * @brief Returns the overall average placement across every single race
 * @return average of all races
 */
double TrackModel::get_overall_average_placement() const{
    int sum = 0;
    int length = 0;
    for(size_t i = 0; i < this->tracks.size(); i++){
        for(size_t j = 0; j < this->tracks.at(i)->get_all_placements().size(); j++)
            sum += this->tracks.at(i)->get_all_placements().at(j);
        length += this->tracks.at(i)->get_all_placements().size();
    }
    return sum * 1.0 / length;
}

/**
 * @brief Returns the average points earned per race.  (1st place = 15, 12th place = 1, for example)
 * @return average points
 */
double TrackModel::get_average_points() const{
    int sum = 0;
    int length = 0;
    for(size_t i = 0; i < this->tracks.size(); i++){
        for(size_t j = 0; j < this->tracks.at(i)->get_all_placements().size(); j++){
            switch(this->tracks.at(i)->get_all_placements().at(j)){
                case 1: sum += 15; break;
                case 2: sum += 12; break;
                case 3: sum += 10; break;
                case 4: sum += 9; break;
                case 5: sum += 8; break;
                case 6: sum += 7; break;
                case 7: sum += 6; break;
                case 8: sum += 5; break;
                case 9: sum += 4; break;
                case 10: sum += 3; break;
                case 11: sum += 2; break;
                case 12: sum++; break;
                default: break;
            }
        }
        length += this->tracks.at(i)->get_all_placements().size();
    }
    return sum * 1.0 / (length / 12);   // each mogi = 12 races
}
