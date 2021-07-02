#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void initMaps(map<int, string> &notes, map<int, string> &intervals);

int main() {
    map<int, string> notes;
    map<int, string> intervals;
    int run = 1;
    int steps = 0;
    int base = 0;
    int finalNote = 0;

    initMaps(notes, intervals);

    srand(time(0));

    while(run) {
        steps = rand() % 12;
        base = rand() % 12;
        finalNote = (steps + base) % 12;

        cout << notes[finalNote] << " is a " << intervals[steps] << " above " << notes[base] << endl;
        break;
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