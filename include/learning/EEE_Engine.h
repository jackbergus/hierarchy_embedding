//
// Created by giacomo on 29/12/19.
//

#ifndef HIERARCHY_TESTS_EEE_ENGINE_H
#define HIERARCHY_TESTS_EEE_ENGINE_H

// Author: Zhi-Ting Hu, Po-Yao Huang
// Date: 2014.10.26
#pragma once

#include <vector>
#include <stdint.h>
#include <utility>
#include <iostream>
#include <fstream>
#include <learning/Dataset.h>
#include <naryTree.h>
#include <fixed_bimap.h>
#include "Hierarchy.h"

class EEEngine {
public:
    EEEngine(DistMetricMode metric, const size_t dim_embedding, naryTree &tree,
             fixed_bimap<std::string, size_t> &bimap);
    ~EEEngine();

    // for analysis
    Hierarchy &entity_category_hierarchy() {
        return entity_category_hierarchy_;
    }

    inline int num_entity() { return num_entity_category; }

    // TODO: Given a the current batch, all the negative samples are the pairs of the objects that are not within the hierarchy
    //void SampleNegEntities(Datum &datum);

    // TODO: the minibatch will be the set of all the elements that are within the hierarchy
    /*void ThreadCreateMinibatch(const std::vector<int> &next_minibatch_data_idx,
                               std::vector<Datum> &next_minibatch);*/


    void InitEntityCategories(size_t num_entities_and_categories);

    Hierarchy entity_category_hierarchy_;

    /**
     * Storing the hierarchy accordingly to the tree information.
     *
     * @param tree              Tree from which we want to store the hierarchies
     * @param levelId           Level id from which the visit is started: initially zero if the tree is the tree node.
     */
    void ReadHierarchyIdWithLevel(naryTree &tree, size_t levelId = 0);

private:
    size_t num_neg_sample_;
    size_t num_entity_category;
    naryTree& treeRef;
    fixed_bimap<std::string, size_t>& bijection;
};


#endif //HIERARCHY_TESTS_EEE_ENGINE_H