#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

enum {WHITE,GRAY,BLACK};


struct Node{
    std::string contry;
    std::string toContry;
    int extr=0;
    std::vector<Node*> vertex;
    int notImportantt=INT32_MAX;
    bool amBe=false;
    int color = WHITE;
};
int maxi=0;

// DFS
void Walking(Node* root){
    root->amBe= true;
    std::queue <Node*> qe;

    uint32_t n=root->vertex.size();
    for (uint32_t i=0;i<n;i++){
        if ((root->notImportantt+1)<root->vertex[i]->notImportantt){
            root->vertex[i]->notImportantt= std::min(root->notImportantt+1,root->vertex[i]->notImportantt);
            qe.push(root->vertex[i]);
        }

        if (!root->vertex[i]->amBe){
            root->vertex[i]->amBe=true;
            qe.push(root->vertex[i]);
        }
    }
    while (!qe.empty()){
        Walking(qe.front());
        qe.pop();
    }

}

int main(int argc, char** argv) {
    std::ifstream file;
    file.open(argv[1]);
    if (!file.is_open()){
        return 0;
    }
    uint32_t n;
    file>>n;

    std::vector<Node*> Graph;

    for (uint32_t i=0;i<n;i++){
        Graph.push_back(new Node());
    }

    for (uint32_t i=0;i<n;i++){
        uint32_t count;
        file>>count;
        file>> Graph[i]->contry;
        file>>count;
        for (uint32_t j=0;j<count;j++){
            uint32_t index;
            file>>index;
            Graph[i]->vertex.push_back(Graph[index]);
        }
    }

    int maxi;

    for (uint32_t i=0;i<n;i++){
        Graph[i]->notImportantt=0;
        Walking(Graph[i]);
        maxi=0;
        std::string toCountry;
        for (uint32_t i=0;i<n;i++){
            if (Graph[i]->notImportantt!=INT32_MAX){
                if (Graph[i]->notImportantt>maxi){
                    maxi=Graph[i]->notImportantt;
                    toCountry=Graph[i]->contry;
                }
                Graph[i]->notImportantt=INT32_MAX;
            }
        }
        Graph[i]->toContry=toCountry;
        Graph[i]->extr=maxi;
    }
    for (uint32_t i=0;i<n;i++){
        std::cout<<Graph[i]->contry<<" "<<Graph[i]->extr<<" до: "<<Graph[i]->toContry<<std::endl;
    }


    for (uint32_t i=0;i<n;i++){

        delete Graph[i];
    }
    return 0;
}