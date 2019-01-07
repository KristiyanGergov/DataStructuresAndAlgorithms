#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1000000000;

void dijkstra(int start, vector<int> & dist, vector<int> & p, vector<vector<pair<int, int>>> & adj) {
	int vertices = adj.size();
	dist.assign(vertices, INF);
	p.assign(vertices, -1);

	dist[start] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({ 0, start });
	while (!q.empty()) {
		int endVertex = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != dist[endVertex])
			continue;

		for (auto edge : adj[endVertex]) {
			int to = edge.first;
			int len = edge.second;

			if (dist[endVertex] + len < dist[to]) {
				dist[to] = dist[endVertex] + len;
				p[to] = endVertex;
				q.push({ dist[to], to });
			}
		}
	}
}