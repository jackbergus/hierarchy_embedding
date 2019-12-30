//
// Created by giacomo on 30/12/19.
//

#ifndef HIERARCHY_TESTS_TESTINGLEARNING_H
#define HIERARCHY_TESTS_TESTINGLEARNING_H

#include <Testing.h>
#include <naryTree.h>
#include <fixed_bimap.h>
#include <learning/EEE_Engine.h>
#include <learning/HierarchyLearning.h>


class TestingLearning : public Testing<size_t> {
    naryTree tree{0};
    size_t id = 0, num_entities_and_classes = 1; //num_entities_and_classes is initialized with 1, because the root will be added automatically

   // std::cout << "Generating the positive examples" << std::endl;
    std::map<std::string, std::set<std::string>> positiveExamples;
    fixed_bimap<std::string, size_t>             bimap;             // Bijection between path as a string and the id
    std::set<std::string>                       allNodes;           // Containing all the nodes within the hierarchy
    size_t                                      dimEmbedding;   // Vector dimension
    EEEngine*                                   ee_engine_;
    HierarchyLearning*                          trainer;


public:
    TestingLearning(size_t maximumBranchingFactor, size_t maximumHeight, size_t vectorDimension);

    ~TestingLearning() {
        delete ee_engine_;
        delete trainer;
    }

protected:
    void initialize_hierarchy_with_all_paths(const std::vector<std::vector<size_t>> &element);
    size_t getVectorRepresentation(const std::vector<size_t> &current);
    double similarity(const size_t &lhs, const size_t &rhs);
    void generateTopKCandidates(PollMap<double, std::string> &map, const std::vector<size_t> &current);
    void finalizeDataIngestion();
};


void testing_learning_method();


void batch_learning(const std::vector<Datum> &batch, HierarchyLearning &trainer, int iterations);


#endif //HIERARCHY_TESTS_TESTINGLEARNING_H
