4/5/2022:

Topics:
	Assigning work for data format process
	Discuss data format process
	Discuss how we will format graph

Discuss how we will format graph:
	Copy node structure from a tree we’ve previously made, insert node data from data set, DFS, BFS run parallel
	Must discuss layovers/tolerance
		Edges have weight based on airport
		Layovers aren’t built into data set, but dijkstra’s should take into consideration indirect flights by traversing through several nodes
		Possibly add weight based on strongly connected components
		Possibly implementing the weight of each edge in each node when building graph. Not using this idea currently, but keeping it in mind. 
	Using regular non-extended airports from OpenFlights (airports.dat)
	Nodes using airport location data, edges using
		Assuming that each flight back and forth can go to the same airport
		Edges pointing to departures, it’s assumed that they go both ways ^
		^ As long as they are connected 

Assigning work for data format process
	Some work on processing data, some work on algorithm
	Nick+Madigan working on processing data, work on making graph together, keeping other team informed about progress as necessary 
		Nick: routes
		Madigan: airports
	Elizabeth+Pranet working on algorithm
		Elizabeth: DFS
		Pranet: DFS

Discuss how we will format graph
	Airport data: Only need 3 letter name + name (for output) + co-ords (2nd, 5th, and co-ord column)
	Route data: Only need Source Airport ID, Destination ID(6th and 4th columns)

