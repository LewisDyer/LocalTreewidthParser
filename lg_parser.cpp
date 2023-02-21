#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <boost/graph/adjacency_list.hpp>

using namespace boost;

using Graph = adjacency_list<vecS, vecS, undirectedS, property<vertex_name_t, int>, property<edge_weight_t, int>>;

/**
 * @param filename a string giving the pathname of an .lg file
 * @return The graph parsed from that file.
*/
Graph parse_lg(std::string filename) {
    std::ifstream infile(filename);
    if(!infile) {
        std::cerr << "Cannot open file " << filename << std::endl;
        return 1;
    }

    std::string line;
    Graph g;
    while (std::getline(infile, line)) {
        tokenizer<> tok(line);
        std::string token = *tok.begin();
        if (token == "v") {
            int v, label;
            tokenizer<>::iterator it = tok.begin(); ++it;
            v = std::stoi(*it);
            ++it;
            label = std::stoi(*it);
            add_vertex(v, g);
            boost::put(boost::vertex_name_t(), g, v, label);
        }
        else if (token == "e") {
            int u, v, no_papers;
            tokenizer<>::iterator it = tok.begin(); ++it;
            u = std::stoi(*it);
            ++it;
            v = std::stoi(*it);
            ++it;
            no_papers = std::stoi(*it);
            add_edge(u, v, no_papers, g);
        }
    }

    return g;
}



int main(int argc, char const *argv[])
{
    /* code */
    std::cout <<"Hello world!\n";

    Graph G = parse_lg("data/path.lg");
}
