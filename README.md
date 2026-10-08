# University Campus Network Planner

##  Project Description

The **University Campus Network Planner** is a C-based application designed to help plan a low-cost network connecting multiple buildings across a university campus.

The project represents the campus buildings as **vertices** and the possible network connections between them as **edges** with associated installation costs. Using this weighted graph representation, the application applies **Prim’s Minimum Spanning Tree (MST) algorithm** to determine the minimum-cost set of connections required to connect all buildings while avoiding unnecessary connections.

The program provides a simple menu-driven interface where users can:

* Enter the names of campus buildings.
* Define the connection costs between buildings.
* View the complete connection cost matrix.
* Select a starting building for the MST calculation.
* Generate and display the **Minimum Spanning Tree**.
* View the total installation cost and number of connections required.
* Detect when the campus network graph is disconnected and an MST cannot be formed.

##  Concepts Used

This project demonstrates important **Data Structures and Algorithms** concepts, including:

* **Graph representation using an adjacency matrix**
* **Weighted undirected graphs**
* **Minimum Spanning Tree**
* **Prim’s Algorithm**
* **Greedy algorithm technique**
* **Arrays and strings in C**
* **Menu-driven programming**

##  How Prim’s Algorithm Is Used

Prim’s algorithm starts from the building selected by the user and repeatedly chooses the **minimum-cost connection** that adds a new building to the growing network.

The process continues until every building is connected. The resulting set of connections forms the **Minimum Spanning Tree**, providing the minimum possible total installation cost while maintaining connectivity.


##  Output

The program displays:

* The campus connection cost matrix
* The selected MST connections
* The source and destination buildings for each connection
* The cost of each connection
* The total minimum installation cost
* The number of connections in the MST
* A message when the graph is disconnected and an MST cannot be formed

##  Technologies

**Language:** C
**Core Algorithm:** Prim’s Minimum Spanning Tree
