#include <iostream>
#include <thread>
#include <vector>

#include "Vehicle.h"
#include "Street.h"
#include "Intersection.h"
#include "Graphics.h"

#define PARIS_INTERSECT1_X    (size_t)(385/SCALE_DOWN_FACTOR)   
#define PARIS_INTERSECT1_Y    (size_t)(270/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT2_X    (size_t)(1240/SCALE_DOWN_FACTOR)   
#define PARIS_INTERSECT2_Y    (size_t)(80/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT3_X    (size_t)(1625/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT3_Y    (size_t)(75/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT4_X    (size_t)(2110/SCALE_DOWN_FACTOR) 
#define PARIS_INTERSECT4_Y    (size_t)(75/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT5_X    (size_t)(2840/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT5_Y    (size_t)(175/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT6_X    (size_t)(3060/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT6_Y    (size_t)(680/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT7_X    (size_t)(2800/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT7_Y    (size_t)(1400/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT8_X    (size_t)(400/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT8_Y    (size_t)(1100/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT9_X    (size_t)(1700/SCALE_DOWN_FACTOR)
#define PARIS_INTERSECT9_Y    (size_t)(900/SCALE_DOWN_FACTOR)

#define NY_INTERSECT1_X    (size_t)(1430/SCALE_DOWN_FACTOR)   
#define NY_INTERSECT1_Y    (size_t)(625/SCALE_DOWN_FACTOR)
#define NY_INTERSECT2_X    (size_t)(2575/SCALE_DOWN_FACTOR)   
#define NY_INTERSECT2_Y    (size_t)(1260/SCALE_DOWN_FACTOR)
#define NY_INTERSECT3_X    (size_t)(2200/SCALE_DOWN_FACTOR)
#define NY_INTERSECT3_Y    (size_t)(1950/SCALE_DOWN_FACTOR)
#define NY_INTERSECT4_X    (size_t)(1000/SCALE_DOWN_FACTOR) 
#define NY_INTERSECT4_Y    (size_t)(1350/SCALE_DOWN_FACTOR)
#define NY_INTERSECT5_X    (size_t)(400/SCALE_DOWN_FACTOR)
#define NY_INTERSECT5_Y    (size_t)(1000/SCALE_DOWN_FACTOR)
#define NY_INTERSECT6_X    (size_t)(750/SCALE_DOWN_FACTOR)
#define NY_INTERSECT6_Y    (size_t)(250/SCALE_DOWN_FACTOR)

// Paris
void createTrafficObjects_Paris(std::vector<std::shared_ptr<Street>> &streets, std::vector<std::shared_ptr<Intersection>> &intersections, std::vector<std::shared_ptr<Vehicle>> &vehicles, std::string &filename, int nVehicles)
{
    // assign filename of corresponding city map
    filename = "../data/paris.jpg";

    // init traffic objects
    int nIntersections = 9;
    for (size_t ni = 0; ni < nIntersections; ni++)
    {
        intersections.push_back(std::make_shared<Intersection>());
    }

    // position intersections in pixel coordinates (counter-clockwise)
    intersections.at(0)->setPosition(PARIS_INTERSECT1_X, PARIS_INTERSECT1_Y);
    intersections.at(1)->setPosition(PARIS_INTERSECT2_X, PARIS_INTERSECT2_Y);
    intersections.at(2)->setPosition(PARIS_INTERSECT3_X, PARIS_INTERSECT3_Y);
    intersections.at(3)->setPosition(PARIS_INTERSECT4_X, PARIS_INTERSECT4_Y);
    intersections.at(4)->setPosition(PARIS_INTERSECT5_X, PARIS_INTERSECT5_Y);
    intersections.at(5)->setPosition(PARIS_INTERSECT6_X, PARIS_INTERSECT6_Y);
    intersections.at(6)->setPosition(PARIS_INTERSECT7_X, PARIS_INTERSECT7_Y);
    intersections.at(7)->setPosition(PARIS_INTERSECT8_X, PARIS_INTERSECT8_Y);
    intersections.at(8)->setPosition(PARIS_INTERSECT9_X, PARIS_INTERSECT9_Y); // central plaza

    // create streets and connect traffic objects
    int nStreets = 8;
    for (size_t ns = 0; ns < nStreets; ns++)
    {
        streets.push_back(std::make_shared<Street>());
        streets.at(ns)->setInIntersection(intersections.at(ns));
        streets.at(ns)->setOutIntersection(intersections.at(8));
    }

    // add vehicles to streets
    for (size_t nv = 0; nv < nVehicles; nv++)
    {
        vehicles.push_back(std::make_shared<Vehicle>());
        vehicles.at(nv)->setCurrentStreet(streets.at(nv%nStreets));
        vehicles.at(nv)->setCurrentDestination(intersections.at(8));
    }
}

// NYC
void createTrafficObjects_NYC(std::vector<std::shared_ptr<Street>> &streets, std::vector<std::shared_ptr<Intersection>> &intersections, std::vector<std::shared_ptr<Vehicle>> &vehicles, std::string &filename, int nVehicles)
{
    // assign filename of corresponding city map
    filename = "../data/nyc.jpg";

    // init traffic objects
    int nIntersections = 6;
    for (size_t ni = 0; ni < nIntersections; ni++)
    {
        intersections.push_back(std::make_shared<Intersection>());
    }

    // position intersections in pixel coordinates
    intersections.at(0)->setPosition(NY_INTERSECT1_X, NY_INTERSECT1_Y);
    intersections.at(1)->setPosition(NY_INTERSECT2_X, NY_INTERSECT2_Y);
    intersections.at(2)->setPosition(NY_INTERSECT3_X, NY_INTERSECT3_Y);
    intersections.at(3)->setPosition(NY_INTERSECT4_X, NY_INTERSECT4_Y);
    intersections.at(4)->setPosition(NY_INTERSECT5_X, NY_INTERSECT5_Y);
    intersections.at(5)->setPosition(NY_INTERSECT6_X, NY_INTERSECT6_Y);

    // create streets and connect traffic objects
    int nStreets = 7;
    for (size_t ns = 0; ns < nStreets; ns++)
    {
        streets.push_back(std::make_shared<Street>());
    }

    streets.at(0)->setInIntersection(intersections.at(0));
    streets.at(0)->setOutIntersection(intersections.at(1));

    streets.at(1)->setInIntersection(intersections.at(1));
    streets.at(1)->setOutIntersection(intersections.at(2));

    streets.at(2)->setInIntersection(intersections.at(2));
    streets.at(2)->setOutIntersection(intersections.at(3));

    streets.at(3)->setInIntersection(intersections.at(3));
    streets.at(3)->setOutIntersection(intersections.at(4));

    streets.at(4)->setInIntersection(intersections.at(4));
    streets.at(4)->setOutIntersection(intersections.at(5));

    streets.at(5)->setInIntersection(intersections.at(5));
    streets.at(5)->setOutIntersection(intersections.at(0));

    streets.at(6)->setInIntersection(intersections.at(0));
    streets.at(6)->setOutIntersection(intersections.at(3));

    // add vehicles to streets
    for (size_t nv = 0; nv < nVehicles; nv++)
    {
        vehicles.push_back(std::make_shared<Vehicle>());
        vehicles.at(nv)->setCurrentStreet(streets.at(nv%nIntersections));
        vehicles.at(nv)->setCurrentDestination(intersections.at(nv%nIntersections));
    }
}

/* Main function */
int main()
{
    /* PART 1 : Set up traffic objects */

    // create and connect intersections and streets
    std::vector<std::shared_ptr<Street>> streets;
    std::vector<std::shared_ptr<Intersection>> intersections;
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    std::string backgroundImg;
    int nVehicles = 6;
    createTrafficObjects_Paris(streets, intersections, vehicles, backgroundImg, nVehicles);

    /* PART 2 : simulate traffic objects */

    // simulate intersection
    std::for_each(intersections.begin(), intersections.end(), [](std::shared_ptr<Intersection> &i) {
        i->simulate();
    });

    // simulate vehicles
    std::for_each(vehicles.begin(), vehicles.end(), [](std::shared_ptr<Vehicle> &v) {
        v->simulate();
    });

    /* PART 3 : Launch visualization */

    // add all objects into common vector
    std::vector<std::shared_ptr<TrafficObject>> trafficObjects;
    std::for_each(intersections.begin(), intersections.end(), [&trafficObjects](std::shared_ptr<Intersection> &intersection) {
        std::shared_ptr<TrafficObject> trafficObject = std::dynamic_pointer_cast<TrafficObject>(intersection);
        trafficObjects.push_back(trafficObject);
    });

    std::for_each(vehicles.begin(), vehicles.end(), [&trafficObjects](std::shared_ptr<Vehicle> &vehicles) {
        std::shared_ptr<TrafficObject> trafficObject = std::dynamic_pointer_cast<TrafficObject>(vehicles);
        trafficObjects.push_back(trafficObject);
    });

    // draw all objects in vector
    Graphics *graphics = new Graphics();
    graphics->setBgFilename(backgroundImg);
    graphics->setTrafficObjects(trafficObjects);
    graphics->simulate();
}
