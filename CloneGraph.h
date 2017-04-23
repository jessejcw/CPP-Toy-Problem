//
// Created by jesse_wang on 3/22/2017.
//

#ifndef CODING1_CLONEGRAPH_H
#define CODING1_CLONEGRAPH_H

#include "inc_me.h"

class CloneGraph {
public:

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode* node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> graph;
        UndirectedGraphNode* p1 = node;
        UndirectedGraphNode* p2 = new UndirectedGraphNode(p1->label);
        queue<UndirectedGraphNode*> q1;
        graph[p1] = p2;
        q1.push(p1);
        while (!q1.empty()) {
            p1 = q1.front();
            p2 = graph[p1];
            q1.pop();
            for (int i = 0; i < p1->neighbors.size(); i++) {
                UndirectedGraphNode* nbr1 = p1->neighbors[i];
                if (graph.count(nbr1)) {
                    p2->neighbors.push_back(graph[nbr1]);
                } else {
                    UndirectedGraphNode* node2 = new UndirectedGraphNode(nbr1->label);
                    graph[nbr1] = node2;
                    p2->neighbors.push_back(node2);
                    q1.push(nbr1);
                }
            }
        }
        return graph[node];
    }

};


#endif //CODING1_CLONEGRAPH_H
