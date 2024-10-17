---
lab:
    title: 'Data Structures - Exploring Planets with Arrays, Linked Lists, and Trees'
---
# Extras 01: Data Structures in Space Exploration
## Overview
In this extras, you will explore fundamental data structures such as arrays, linked lists, and binary trees to solve common problems in space exploration missions. You’ll simulate managing resources, planets, and crew members, utilizing different data structures to store and access information efficiently.

## Exercise Instructions
1. Use an array to track discovered planets.
2. Implement a linked list to manage space station docking schedules.
3. Create a binary tree to map solar systems and retrieve information about planets based on their distance from the sun.

### Part 1: Managing Discovered Planets with Arrays
In this exercise, you'll use an array to store the names of newly discovered planets in a distant galaxy.

**Step 1: Define the Array** Create an array of strings to store the names of up to 100 planets discovered during the mission. You'll input the names of planets, and then display them in the order of discovery.

Sample Code:
```c
#include <stdio.h>
#include <string.h>

#define MAX_PLANETS 100
#define MAX_NAME_LEN 50

int main() {
    char planets[MAX_PLANETS][MAX_NAME_LEN];
    int planet_count = 0;

    // Add planets to the array
    strcpy(planets[planet_count++], "Zora");
    strcpy(planets[planet_count++], "Nexus Prime");
    strcpy(planets[planet_count++], "Arcturus");

    // Display the list of discovered planets
    printf("Discovered Planets:\n");
    // To do: display the list by iterating through the planets array

    return 0;
}
```

**Step 2: Add More Planets** Modify the code to allow the user to input the names of newly discovered planets until they choose to stop. Ensure the program prevents the array from exceeding its maximum capacity.

### Part 2: Managing Docking Schedules with Linked Lists
In this exercise, you will implement a linked list to manage the docking schedules of ships at your space station.

**Step 1: Define the Linked List Node** Each node in the linked list will store information about a ship's name and its scheduled docking time.

Sample Code:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ship {
    char name[50];
    int docking_time;
    // To do: Linked list structure of "next" goes here
} Ship;

void addShip(Ship** head, char* name, int time) {
    Ship* newShip = (Ship*)// To do: dynamic allocation ;
    strcpy(newShip->name, name);
    newShip->docking_time = time;
    newShip->next = *head;
    *head = newShip;
}

void printDockingSchedule(Ship* head) {
    Ship* current = head;
    while (current != NULL) {
        printf("Ship %s docking at %d hours.\n", current->name, current->docking_time);
        current = current->next;
    }
}

int main() {
    Ship* docking_schedule = NULL;

    // Add ships to the schedule
    addShip(&docking_schedule, "SS Voyager", 9);
    addShip(&docking_schedule, "Galactic Express", 11);
    addShip(&docking_schedule, "Orion Star", 14);

    // Print the docking schedule
    printDockingSchedule(docking_schedule);

    return 0;
}
```

**Step 2: Update Docking Schedules** Modify the code to allow users to update or remove docking schedules as ships arrive or leave the station.

### Part 3: Mapping Solar Systems with Binary Trees
In this exercise, you’ll implement a binary tree to map a solar system's planets based on their distance from the sun.

**Step 1: Define the Binary Tree Node** Each node will represent a planet and store its name and distance from the sun.

Sample Code:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Planet {
    char name[50];
    int distance_from_sun;
    // To do: Implement the binary tree with "left" and "right" node
	// left
	// right
} Planet;

Planet* createPlanet(char* name, int distance) {
    Planet* newPlanet = (Planet*)malloc(sizeof(Planet));
    strcpy(newPlanet->name, name);
    newPlanet->distance_from_sun = distance;
    newPlanet->left = newPlanet->right = NULL;
    return newPlanet;
}

Planet* addPlanet(Planet* root, char* name, int distance) {
    if (root == NULL) {
        return createPlanet(name, distance);
    }
    if (distance < root->distance_from_sun) {
        root->left = addPlanet(root->left, name, distance);
    } else {
        root->right = addPlanet(root->right, name, distance);
    }
    return root;
}

void printSolarSystem(Planet* root) {
    if (root != NULL) {
        printSolarSystem(root->left);
        printf("%s is %d million km from the sun.\n", root->name, root->distance_from_sun);
        printSolarSystem(root->right);
    }
}

int main() {
    Planet* solar_system = NULL;

    // Add planets to the solar system
    solar_system = addPlanet(solar_system, "Mercury", 58);
    solar_system = addPlanet(solar_system, "Venus", 108);
    solar_system = addPlanet(solar_system, "Earth", 150);
    solar_system = addPlanet(solar_system, "Mars", 228);

    // Print the solar system map
    printSolarSystem(solar_system);

    return 0;
}
```

**Step 2: Expand the Solar System** Allow the user to input additional planets and distances to dynamically build the solar system.
Think `scanf`.

**Next Steps:**
1. Explore how each data structure is used in real-world applications, such as memory management, fast retrieval, and scheduling.
2. Expand the exercises by experimenting with more complex operations like sorting planets or managing docking conflicts using advanced linked list techniques.

Stay curious and keep exploring the cosmos of data structures!
