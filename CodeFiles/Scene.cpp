//
//  Scene.cpp
//  MedCheck1.3
//
//  Created by Heath Banak on 7/8/22.
//

#include <iostream>
#include <iomanip>

using namespace std;

#include "Scene.h"

Scene::Scene() {
    today_ = new Date;
    title_ = "No title";
    titleLength_ = title_.size();
    dateLength_ = (today_->getDisplayDate()).size();
}

Scene::Scene(string title) {
    today_ = new Date;
    title_ = title;
    titleLength_ = title_.size();
    dateLength_ = (today_->getDisplayDate()).size();
}

void Scene::printTitleDate() {
    int dateLength = dateLength_ + 8;
    cout << setw(dateLength) << setfill('=') << "" << endl;
    cout << setw((dateLength - titleLength_) / 2) << setfill(' ') << "";
    cout << title_;
    cout << setw((dateLength - titleLength_) / 2) << setfill(' ') << "" << endl;
    cout << setw(dateLength) << setfill('=') << "" << endl;
    cout << setw((dateLength - dateLength_) / 2) << setfill(' ') << "";
    cout << today_->getDisplayDate();
    cout << setw((dateLength - dateLength_) / 2) << setfill(' ') << "" << endl;
    cout << setw(dateLength) << setfill('=') << "" << endl;
}

void Scene::endScene() {
    int dateLength = dateLength_ + 8;
    cout << setw(dateLength) << setfill('-') << "" << endl;
}
