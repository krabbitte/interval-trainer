#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void initMaps(map<int, string> &notes, map<int, string> &intervals);
bool isValidNote(string note);
int findNoteIndex(string note, map<int, string> notes);

int main() {
    map<int, string> notes;
    map<int, string> intervals;
    vector<int> noteset;
    int run = 1;
    int steps = 0;
    int base = 0;
    int finalNote = 0;
    string guess;
    string input;

    initMaps(notes, intervals);

    cout << "which notes should be included? done to stop, all for all" << endl;

    do {
        cin >> input;
        if(input == "all") {
            for(int i = 0; i < 12; i++) {
                noteset.push_back(i);
            }
            break;
        } else {
            if (isValidNote(input)) {
                noteset.push_back(findNoteIndex(input, notes));
            } else if (input != "done") {
                cout << "not a valid note" << endl;
            }
        }
    } while (input != "done");

    for(int i = 0; i < noteset.size(); i++)
        cout << noteset[i] << endl;

    cout << noteset.size() << endl;

    srand(time(0));

    while(run) {
        steps = rand() % 12;
        base = rand() % noteset.size();
        finalNote = (steps + noteset[base]) % 12;

        cout << "What note is a " << intervals[steps] << " from " << notes[noteset[base]] << endl;
        cin >> guess;

        if (guess == "exit") {
            break;
        } else if (guess == notes[finalNote]){
            cout << "correct!" << endl;
        } else {
            cout << "false" << endl;
            cout << notes[finalNote] << " is a " << intervals[steps] << " from " << notes[noteset[base]] << endl;
        }
    }

    return 0;
}

void initMaps(map<int, string> &notes, map<int, string> &intervals){
    notes[0] = "C";
    notes[1] = "C#";
    notes[2] = "D";
    notes[3] = "D#";
    notes[4] = "E";
    notes[5] = "F";
    notes[6] = "F#";
    notes[7] = "G";
    notes[8] = "G#";
    notes[9] = "A";
    notes[10] = "A#";
    notes[11] = "B";

    intervals[0] = "Unison";
    intervals[1] = "Minor Second";
    intervals[2] = "Major Second";
    intervals[3] = "Minor Third";
    intervals[4] = "Major Third";
    intervals[5] = "Perfect Fourth";
    intervals[6] = "Tritone";
    intervals[7] = "Perfect Fifth";
    intervals[8] = "Minor Sixth";
    intervals[9] = "Major Sixth";
    intervals[10] = "Minor Seventh";
    intervals[11] = "Major Seventh";
}

bool isValidNote(string note){
    if (note == "A" || note == "A#" || note == "B" || note == "C" || note == "C#" || note == "D" || note == "D#" || note == "E" || note == "F" || note == "F#" || note == "G" || note == "G#") {
        return true;
    }

    return false;
}

int findNoteIndex(string note, map<int, string> notes) {
    for(int i = 0; i < 12; i++) {
        if(notes[i] == note)
            return i;
    }
    return -1;
}
