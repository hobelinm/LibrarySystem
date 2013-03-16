/******************************************************************************
* Audio class <Audio.cpp>:
* This class implements Audio assets
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "Audio.h"

using namespace std;
Audio::Audio()
{
    isInitialized    = false;
    type             = AUDIO_TYPE;
    genre            = "";
    title            = "";
    year             = "";
    availableCopies  = AUDIO_COPIES;
    for(int i = 0; i < AUDIO_COPIES; i++) {
        resourceCopies[i] = ""; }
}

// *** Destructor *** //
Audio::~Audio()
{
    // TODO: Implement destructor
}

// *** Inherited method section *** //
Object* Audio::create() const 
{
    return new Audio;
}

bool Audio::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_92 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_92 << endl << endl;
        return false; }
    const Audio &audio = static_cast<const Audio &>(obj);
    if(audio.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_92 << endl << endl;
        return false; }
    // Compare by genre, then by year, then by title
    if(this->genre.compare(audio.genre) == 0) {
        if(this->year.compare(audio.year) == 0) {
            return (this->title.compare(audio.title) == 0); }
        return (this->year.compare(audio.year) == 0); }

    return (this->genre.compare(audio.genre) == 0);
}

bool Audio::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_93 << endl << endl;
        return true; }
    if(isInitialized == false) {
        cout << endl<< ERROR_21 << endl;
        cout << "--> At " << MID_93 << endl;
        return true; }
    return !this->operator==(obj);
}

bool Audio::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_94 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_94 << endl << endl;
        return false; }
    const Audio &audio = static_cast<const Audio &>(obj);
    if(audio.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_94 << endl << endl;
        return false; }
    // Compare by genre, then by year, then by title
    if(this->genre.compare(audio.genre) == 0) {
        if(this->year.compare(audio.year) == 0) {
            return (this->title.compare(audio.title) < 0); }
        return (this->year.compare(audio.year) < 0); }
    return (this->genre.compare(audio.genre) < 0);
}

bool Audio::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_95 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_95 << endl << endl;
        return false; }
    const Audio &audio = static_cast<const Audio &>(obj);
    if(audio.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_95 << endl << endl;
        return false; }
    // Compare by genre, then by year, then by title
    if(this->genre.compare(audio.genre) == 0) {
        if(this->year.compare(audio.year) == 0) {
            return (this->title.compare(audio.title) <= 0); }
        return (this->year.compare(audio.year) <= 0); }
    return (this->genre.compare(audio.genre) <= 0);
}

bool Audio::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_96 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_96 << endl << endl;
        return false; }
    const Audio &audio = static_cast<const Audio &>(obj);
    if(audio.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_96 << endl << endl;
        return false; }
    // Compare by genre, then by year, then by title
    if(this->genre.compare(audio.genre) == 0) {
        if(this->year.compare(audio.year) == 0) {
            return (this->title.compare(audio.title) > 0); }
        return (this->year.compare(audio.year) > 0); }
    return (this->genre.compare(audio.genre) > 0); 
}

bool Audio::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_97 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_97 << endl << endl;
        return false; }
    const Audio &audio = static_cast<const Audio &>(obj);
    // Compare by genre, then by year, then by title
    if(this->genre.compare(audio.genre) == 0) {
        if(this->year.compare(audio.year) == 0) {
            return (this->title.compare(audio.title) >= 0); }
        return (this->year.compare(audio.year) >= 0); }
    return (this->genre.compare(audio.genre) >= 0);
}

string Audio::populate(string cmd)
{
    type = AUDIO_TYPE;
    if(cmd.substr(0, cmd.find_first_of(RESOURCE_SEPARATOR)) 
        != AUDIO_TYPE_ID) {
        cout << endl << ERROR_24 << endl;
        cout << "--> At " << MID_98 << endl << endl;
        return ""; }
    string remaining = cmd.substr(cmd.find_first_of(RESOURCE_SEPARATOR) + 1,
        cmd.size() - cmd.find_first_of(RESOURCE_SEPARATOR) - 1);
    genre = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    remaining = remaining.substr(remaining.find_first_of(RESOURCE_SEPARATOR2)
        + 2, remaining.size() - remaining.find_first_of(RESOURCE_SEPARATOR2)
        - 2);
    isInitialized = true;
    if(remaining.size() <= 0) {
        return getKey(); }
    title = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    if(remaining.size() <= 0) {
        return getKey(); }
    year = remaining.substr(remaining.find_first_of(RESOURCE_SEPARATOR2)
        + 2, remaining.size() - remaining.find_first_of(RESOURCE_SEPARATOR2) 
        - 2);

    return getKey();
}

string Audio::getType() const 
{
    return type;
}

string Audio::getTitle() const 
{
    return title;
}

string Audio::getYear() const 
{
    return year;
}

string Audio::getMonth() const 
{
    cout << endl << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_99 << endl << endl;
    return ""; // Parameter is not supported
}

string Audio::getAuthor() const 
{
    cout << endl << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_100 << endl << endl;
    return ""; // Parameter is not supported
}

string Audio::getGenre() const 
{
    return genre;
}

bool Audio::returnResource(string userId)
{
    if(availableCopies == AUDIO_COPIES) {
        cout << endl << ERROR_27 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_101 << endl << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < AUDIO_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i;
            break; } }
    if(userIdx == -1) {
        cout << endl << ERROR_26 << endl;
        cout << "--> User ID: " << userId << endl;
        cout << "---> Resource: " << getKey() << endl;
        cout << "----> At " << MID_101 << endl << endl;
        return false; }
    resourceCopies[userIdx] = "";
    availableCopies++;
    return true;
}

bool Audio::checkoutResource(string userId)
{
    if(availableCopies <= 0) {
        cout << endl << ERROR_25 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_102 << endl << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < AUDIO_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i; // User found
            break; } }
    if(userIdx != -1) {
        cout << endl << ERROR_28 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_102 << endl << endl;
        return false; }
    for(int i = 0; i < AUDIO_COPIES; i++) {
        if(resourceCopies[i] == "") {
            resourceCopies[i] = userId;
            availableCopies--;
            break; } }
    return true;
}

string Audio::getKey() const 
{
    if(!isInitialized) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_91 << endl << endl; 
        return ""; }
    // Sort by genre, then by year, then by title
     return genre + "-" + year + "-" + title;
}

int Audio::getAvailableCopies() const 
{
    return availableCopies;
}

void Audio::print() const 
{
    unsigned sizes[] = AUDIO_SIZES;
    // Available copies
    cout << "  " << availableCopies << "   ";
    string output = "";
    
    // Title
    string t = title;
    if(t.size() > sizes[1]) {
        t = t.substr(0, sizes[1] - 3);
        t += "... "; }
    if(t.size() < sizes[1]) {
        for(unsigned i = t.size(); i <= sizes[1]; i++) {
            t += " "; } }
    output += t;
    
    // Author
    string a = genre;
    if(a.size() > sizes[2]) {
        a = a.substr(0, sizes[2] - 3);
        a += "... "; }
    if(a.size() < sizes[2]) {
        for(unsigned i = a.size(); i <= sizes[2]; i++) {
            a += " "; } }
    output += a;
    
    // Year
    output += year;
    
    cout << output << endl;
}

void Audio::printResource() const
{
    unsigned sizes[] = AUDIO_SIZES;
    string output = "";
    
    // Title
    string t = title;
    if(t.size() > sizes[1]) {
        t = t.substr(0, sizes[1] - 3);
        t += "... "; }
    if(t.size() < sizes[1]) {
        for(unsigned i = t.size(); i <= sizes[1]; i++) {
            t += " "; } }
    output += t;
    
    // Author
    string a = genre;
    if(a.size() > sizes[2]) {
        a = a.substr(0, sizes[2] - 3);
        a += "... "; }
    if(a.size() < sizes[2]) {
        for(unsigned i = a.size(); i <= sizes[2]; i++) {
            a += " "; } }
    output += a;
    
    // Year
    output += year;
    
    cout << output << endl;
}

