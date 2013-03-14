/******************************************************************************
* Video class <Video.cpp>:
* This class implements Video assets
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "Video.h"

using namespace std;
Video::Video()
{
    isInitialized    = false;
    type             = VIDEO_TYPE;
    genre            = "";
    title            = "";
    year             = "";
    availableCopies  = VIDEO_COPIES;
    for(int i = 0; i < VIDEO_COPIES; i++) {
        resourceCopies[i] = ""; }
}

// *** Destructor *** //
Video::~Video()
{
    // TODO: Implement destructor
}

// *** Inherited method section *** //
Object* Video::create() const 
{
    return new Video;
}

bool Video::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_80 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_80 << endl;
        return false; }
    const Video &video = static_cast<const Video &>(obj);
    if(video.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_80 << endl;
        return false; }
    // Compare by genre, then by year, then by title
    if(this->genre.compare(video.genre) == 0) {
        if(this->year.compare(video.year) == 0) {
            return (this->title.compare(video.title) == 0); }
        return (this->year.compare(video.year) == 0); }

    return (this->genre.compare(video.genre) == 0);
}

bool Video::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_81 << endl;
        return true; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_81 << endl;
        return true; }
    return !this->operator==(obj);
}

bool Video::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_82 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_82 << endl;
        return false; }
    const Video &video = static_cast<const Video &>(obj);
    if(video.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_82 << endl;
        return false; }
    // Compare by genre, then by year, then by title
    if(this->genre.compare(video.genre) == 0) {
        if(this->year.compare(video.year) == 0) {
            return (this->title.compare(video.title) < 0); }
        return (this->year.compare(video.year) < 0); }
    return (this->genre.compare(video.genre) < 0);
}

bool Video::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_83 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_83 << endl;
        return false; }
    const Video &video = static_cast<const Video &>(obj);
    if(video.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_83 << endl;
        return false; }
    // Compare by genre, then by year, then by title
    if(this->genre.compare(video.genre) == 0) {
        if(this->year.compare(video.year) == 0) {
            return (this->title.compare(video.title) <= 0); }
        return (this->year.compare(video.year) <= 0); }
    return (this->genre.compare(video.genre) <= 0);
}

bool Video::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_84 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_84 << endl;
        return false; }
    const Video &video = static_cast<const Video &>(obj);
    if(video.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_84 << endl;
        return false; }
    // Compare by genre, then by year, then by title
    if(this->genre.compare(video.genre) == 0) {
        if(this->year.compare(video.year) == 0) {
            return (this->title.compare(video.title) > 0); }
        return (this->year.compare(video.year) > 0); }
    return (this->genre.compare(video.genre) > 0); 
}

bool Video::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_85 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_85 << endl;
        return false; }
    const Video &video = static_cast<const Video &>(obj);
    // Compare by genre, then by year, then by title
    if(this->genre.compare(video.genre) == 0) {
        if(this->year.compare(video.year) == 0) {
            return (this->title.compare(video.title) >= 0); }
        return (this->year.compare(video.year) >= 0); }
    return (this->genre.compare(video.genre) >= 0);
}

string Video::populate(string cmd)
{
    type = VIDEO_TYPE;
    if(cmd.substr(0, cmd.find_first_of(RESOURCE_SEPARATOR)) 
        != VIDEO_TYPE_ID) {
        cout << ERROR_24 << endl;
        cout << "--> At " << MID_86 << endl;
        return ""; }
    string remaining = cmd.substr(cmd.find_first_of(RESOURCE_SEPARATOR) + 1,
        cmd.size() - cmd.find_first_of(RESOURCE_SEPARATOR) - 1);
    genre = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    remaining = remaining.substr(remaining.find_first_of(RESOURCE_SEPARATOR2)
        + 2, remaining.size() - remaining.find_first_of(RESOURCE_SEPARATOR2)
        - 2);
    title = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    
    year = remaining.substr(remaining.find_first_of(RESOURCE_SEPARATOR2)
        + 2, remaining.size() - remaining.find_first_of(RESOURCE_SEPARATOR2) 
        - 2);

    isInitialized = true;
    return getKey();
}

string Video::getType() const 
{
    return type;
}

string Video::getTitle() const 
{
    return title;
}

string Video::getYear() const 
{
    return year;
}

string Video::getMonth() const 
{
    cout << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_87 << endl;
    return ""; // Parameter is not supported
}

string Video::getAuthor() const 
{
    cout << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_88 << endl;
    return ""; // Parameter is not supported
}

string Video::getGenre() const 
{
    return genre;
}

bool Video::returnResource(string userId)
{
    if(availableCopies == VIDEO_COPIES) {
        cout << ERROR_27 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_89 << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < VIDEO_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i;
            break; } }
    if(userIdx == -1) {
        cout << ERROR_26 << endl;
        cout << "--> User ID: " << userId << endl;
        cout << "---> Resource: " << getKey() << endl;
        cout << "----> At " << MID_89 << endl;
        return false; }
    resourceCopies[userIdx] = "";
    return true;
}

bool Video::checkoutResource(string userId)
{
    if(availableCopies <= 0) {
        cout << ERROR_25 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_90 << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < VIDEO_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i; // User found
            break; } }
    if(userIdx != -1) {
        cout << ERROR_28 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_90 << endl;
        return false; }
    for(int i = 0; i < VIDEO_COPIES; i++) {
        if(resourceCopies[i] == "") {
            resourceCopies[i] = userId;
            break; } }
    return true;
}

string Video::getKey() const 
{
    if(!isInitialized) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_91 << endl; 
        return ""; }
    // Sort by genre, then by year, then by title
     return genre + "-" + year + "-" + title;
}

int Video::getAvailableCopies() const 
{
    return availableCopies;
}
