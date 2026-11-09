//https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/description/?envType=daily-question&envId=2026-11-09


import java.util.SortedSet;
import java.util.TreeSet;

class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int[] servicesServed = new int[k];
        int busyServers=0;

        //completionTime , serverID
        PriorityQueue<int[]> serverGettingFreeAt = new PriorityQueue<>((a,b) -> Integer.compare(a[0],b[0]));

        int aL=arrival.length;

        SortedSet<Integer> availableServers = new TreeSet<>();

        for(int i=0;i<k;i++){
            availableServers.add(i);
        }

        for(int i=0;i<aL;i++){
            int arrivalTime= arrival[i];
            int loadTime= load[i];

            int server = i%k;
            
            if(busyServers<k){

                if(availableServers.contains(server)){
                    servicesServed[server]+=1;
                    busyServers+=1;
                    availableServers.remove(server);
                    serverGettingFreeAt.offer(new int[]{arrivalTime+loadTime,server});
                }

                else{
                    // Find next available server
                    Integer nextServer = ((TreeSet<Integer>) availableServers).ceiling(server);

                    // Wrap around
                    if (nextServer == null) {
                        nextServer = availableServers.first();
                    }

                    servicesServed[nextServer]+=1;
                    busyServers+=1;
                    availableServers.remove(nextServer);
                    serverGettingFreeAt.offer(new int[]{arrivalTime+loadTime,nextServer});
                }
            }



            //free all those servers whose endTime is before the arrivable time of next

            if(i+1<aL){
                int nextArrivalTime= arrival[i+1];
                while(!serverGettingFreeAt.isEmpty() && serverGettingFreeAt.peek()[0]<=nextArrivalTime){
                    int[] get =serverGettingFreeAt.poll();
                    availableServers.add(get[1]);
                    busyServers-=1;
                }
            }

        }
        List<Integer> result = new ArrayList<>();

        int max = Arrays.stream(servicesServed).max().getAsInt();
        for(int i=0;i<k;i++){
            if(servicesServed[i]==max){
                result.add(i);
            }
        }
        return result;
    }
}
