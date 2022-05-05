# kyuhahp2-eboyer2-mac18-pkr3
Final project for kyuhahp2-eboyer2-mac18-pkr3

# Project Proposal

## 1. Leading Question
Our goal is to create a search algorithm to the shortest paths between any two airports, using Dijkstra’s and the Strongly Connected Component Algorithms and the OpenFlights dataset. Dijkstra’s Algorithm finds the shortest path between nodes in a graph. Here, those nodes are airports, and the edges are the flight paths from OpenFlights. Strongly Connected Component Algorithms finds components that have the greatest amount of connections going through them, in our case, these are airports with the greatest amount of traffic. If time allows, we also plan to implement a GUI to allow the user to navigate the program. 

## 2. Dataset Acquisition
We will gather data on Airports and flights connecting them from OpenFlights. From the site, we will download the airport database, including over 14,000 airports and the routes database including over 67,000 flights, each in the form of a CSV.

Each airport in the database contains 14 values, only 7 of which we will need at most. We only need the values that allow us to link them to flights, and the information we want to print out. Similarly, the only values we need from the routes database are those that allow us to link them to airports. We will parse the data and discard the values we are not interested in by reading the CSV directly into our C++ program and do all the processing in C++.

In addition, according to the Openflights site, many of the airports will not have routes flying to them. These airports would result in completely disconnected nodes in our graph and are not useful for our leading question. Therefore, we will discard all airports that don’t have any corresponding flights and not include those in our graph.

We will store each airport as a node, and each node will contain all of the routes connecting it to other airports, therefore our storage will be O(A), with A being the number of airports we include as nodes in our graph.

## 3. Graph Algorithms
To identify the shortest path we will implement Dijkstra’s Algorithm. The function inputs will be two airport codes, the starting point and the destination, and the function output will be the shortest routes. The non-negative weights will be distance from the starting vertex as determined by location data from the dataset. Our target runtime will be O(V + E).

To traverse through the airline graph, we will be implementing DFS due to its compatibility with the strongly connected component algorithm we have chosen. However, due to similarities between Dijkstra’s and BFS, we may implement it as well. We will be using Kosaraju’s algorithm to find the strongly connected vertices from the airline graph, which will then be assigned weights that we can use in Dijkstra’s algorithm. The target runtime for this algorithm is also O(V + E).

## 4. Timeline
April 5: Data format and process

April 12: Finish DFS

April 19: Finish Dijkstra’s Algorithm

April 26: Finish strongly connected components

May 3: Finalization/Edits & work on deliverables

May 6: Final Deliverables due
