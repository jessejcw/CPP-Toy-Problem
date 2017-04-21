//
// Created by jesse wang on 3/22/17.
//

#ifndef CODE1_SIMPLIFYPATH_H
#define CODE1_SIMPLIFYPATH_H

#include "inc_me.h"

class SimplifyPath {
public:
    string simplifyPath(string path) {
        string res, curr_dir;
        vector<string> all_dir;

        path.push_back('/');
        for (int i =0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (curr_dir.empty())
                    continue;
                else if (curr_dir == ".") {
                    curr_dir.clear();
                }
                else if (curr_dir == "..") {
                    if (!all_dir.empty()) {
                        all_dir.pop_back();
                    }
                    curr_dir.clear();
                }
            } else {

            }
        }
    }

};


#endif //CODE1_SIMPLIFYPATH_H
