#include "note.h"

USE_NS_MUSIC;
Note::Note(std::string pitch) {
        normalizePitch(pitch);
        setPitch(pitch);
}
Note::Note(const Note &obj) {}

std::string Note::getPitch() { return m_pitch; }

void Note::normalizePitch(const std::string &pitch) {
        auto it = pitchMap.find(pitch);
        if (it != pitchMap.end()) {
                m_pitch = it->second;
        }
}
const std::unordered_map<std::string, std::string> Note::pitchMap = [] {
        // return map
        std::unordered_map<std::string, std::string> r_map;
        // pitchMapf p as pair
        for (const auto &p : enharmonicEquivalents) {
                r_map[p.first] = p.second;
                r_map[p.second] = p.first;
        }

        // Lambda return
        return r_map;
}();

void Note::setPitch(std::string pitch) {
        if (isalpha(pitch[0])) {
                std::toupper(pitch[0]);
        }
        if (pitchMap.find(pitch) != pitchMap.end()) {
                m_pitch = pitch;
        } else {
                std::cerr << pitch << " is not a valid note" << std::endl;
        }
}

void Note::printNoteInfo() {
        std::cout << "Pitch of the note is " << m_pitch << "\n";

        std::cout << std::endl;
}
