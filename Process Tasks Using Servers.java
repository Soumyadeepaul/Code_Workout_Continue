//https://leetcode.com/problems/process-tasks-using-servers/description/?envType=daily-question&envId=2026-11-07



class PQ {
    public PriorityQueue<int[]> create() {
        return new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            }
            return Integer.compare(a[1], b[1]);
        });
    }
}

class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {

        PQ pq = new PQ();

        PriorityQueue<int[]> minPQ = pq.create();

        for (int i = 0; i < servers.length; i++) {
            minPQ.offer(new int[]{servers[i], i});
        }

        int l = tasks.length;
        int[] result = new int[l];

        // {time to free, server index}
        PriorityQueue<int[]> timeToFreeServer = pq.create();

        int currentTime = 0;

        for (int i = 0; i < l; i++) {

            int task = tasks[i];

            currentTime = Math.max(currentTime, i);

            // Add servers that became free by current time
            while (!timeToFreeServer.isEmpty()) {
                int[] get = timeToFreeServer.peek();

                if (get[0] > currentTime) {
                    break;
                }

                timeToFreeServer.poll();
                minPQ.offer(new int[]{servers[get[1]], get[1]});
            }

            // If no server is available, advance time
            if (minPQ.isEmpty()) {

                int[] get = timeToFreeServer.poll();

                currentTime=get[0];

                minPQ.offer(new int[]{servers[get[1]], get[1]});

                // Add all servers free at the same time
                while (!timeToFreeServer.isEmpty()) {
                    int[] next = timeToFreeServer.peek();

                    if (next[0] > get[0]) {
                        break;
                    }

                    timeToFreeServer.poll();
                    minPQ.offer(new int[]{servers[next[1]], next[1]});
                }
            }

            // Select the best available server
            int[] get = minPQ.poll();

            result[i] = get[1];

            // Update server's finishing time
            timeToFreeServer.offer(
                new int[]{task + currentTime, get[1]}
            );
        }

        return result;
    }
}
