#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
1 <= n <= 10^5
1 <= wait[i] <= 10^5

ip -> n = 4 , wait [] = {2 , 2 , 3 , 1};
op -> {4 , 2 , 1 , 0}

*/



vector<int> solve(vector<int>& wait){
    int n = wait.size();
    vector<int>expired(100000 + 5 , 0);

    for(int i : wait){
        expired[i] += -1;
        expired[0] += 1;
    }
    for(int i = 1 ; i <= 1e5 + 1 ; i++){
        expired[i] += expired[i - 1];
    }

    int time = 0;

    vector<int>res;
    priority_queue<int , vector<int> , greater<int>>processed_expired;

    for(int i = 0 ; i < n ; i++){
        while(processed_expired.size() > 0 && processed_expired.top() <= time){
            processed_expired.pop();
        }
        if(wait[i] > time){
            res.push_back(max(0LL ,n - (long long)processed_expired.size() - (n - expired[time])));
            processed_expired.push(wait[i]);
        }else{
            res.push_back(max(0LL , n - (long long)processed_expired.size() - (n - expired[time])));
        }
        time++;
    }
    while(res.size() > 0 && res.back() == 0){
        res.pop_back();
    }
    res.push_back(0);

    return res;
}

int32_t main(){
    int n ; cin >> n;
    vector<int>wait(n);
    for(int i = 0  ; i < n ; i++){
        cin >> wait[i];
    }
    vector<int>res = requestsInQueue(wait);

    for(int i : res){
        cout << i << " ";
    }
    cout<<endl;
    return 0;
}


/*
Here’s a clearer rewrite of the problem:

---

**Problem: Request Processing in a Queue with Expiration**

Amazon Web Services (AWS) is using a server to handle customer requests. 
The server processes these requests in a First In, First Out (FIFO) order. 
There are `n` customer requests placed in a queue, where each request `i` 
has a maximum waiting time `wait[i]`, in seconds. If a request is not processed within 
its maximum waiting time, it expires and is removed from the queue without being served.

At each second:
1. The server processes the first request in the queue.
2. After processing, the request is removed from the queue in the next second.
3. Any requests that expire before being processed are also removed from the queue at the same time.

The server starts processing requests at time `t = 0`, and the first request in the queue is 
processed at that moment. Requests must be processed before their respective expiration times.

**Your task** is to find the number of requests remaining in the queue at each second, 
until all requests have either been processed or expired.

### Notes:
- If a request is processed at time `t`, it is counted as present in the queue 
for that time but is removed at time `t + 1`.
- A request expires if `t` reaches or exceeds `wait[i]` for that request.
- The queue is initially filled with all the requests at time `t = 0`, 
in the order they must be processed.

### Example:

For `wait = [2, 5, 3]`:

- Request 1 has a maximum waiting time of 2 seconds.
- Request 2 has a maximum waiting time of 5 seconds.
- Request 3 has a maximum waiting time of 3 seconds.

**Time Analysis:**

1. At `t = 0`: The server processes Request 1, and the queue has 3 requests.
2. At `t = 1`: Request 1 is removed (it was processed). Request 2 is now first, 
    and Request 3 is second. The queue has 2 requests.
3. At `t = 2`: Request 2 is processed. Request 3 expires because its maximum wait 
    time (3 seconds) is reached. The queue has 1 request.
4. At `t = 3`: Request 2 is still in the queue but is removed after this second.
5. At `t = 4`: The queue is empty.

### Output:

The output should be a list of the number of requests present in the queue at each second, 
starting from `t = 0` until the queue is empty.

For the above example, the output will be: `[3, 2, 1, 0]`.
*/