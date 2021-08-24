struct RMQ {
    int n;  // 배열의 길이
    vector<int> rangeMin;
    RMQ(const vector<int>& array){
        n = array.size();
        rangeMin.resize(n*4);
        init(array,0,n-1,1);
    }

    int init(const vector<int>& array, int left, int right,int node){
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array,left,mid,node * 2);
        int rightMin = init(array, mid + 1, right, node*2+1);
        return rangeMin[node] = min(leftMin,rightMin);
    }


    // 질의 응답.
    int query(int left, int right, int node , int nodeleft, int noderight){
        if(right < nodeleft || noderight < left)    // 두 값이 겹치지 않으면 아주 큰 값 반환.
            return intmax;

        if(left <= nodeleft && noderight <= right)  // 완전히 포함되는 경우.
            return rangeMin[node];

        int mid = (nodeleft + noderight) / 2;
        return min(query(left,right,node*2,nodeleft,mid),
                   query(left,right,node*2+1,mid+1,noderight));
    }

    // 외부에서 호출하기 위한 인터페이스.
    int query(int left, int right){
        return query(left,right,1,0,n-1);
    }

    // 트리 갱신
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight){
        if(index < nodeLeft || index > nodeRight)
            return rangeMin[node];

        if(nodeLeft == nodeRight)   // 리프 노드까지 내려온 경우.
            return rangeMin[node] = newValue;

        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(
                update(index, newValue, node*2, nodeLeft, mid),
                update(index, newValue, node*2+1, mid+1, nodeRight));
    }

    // 외부에서 호출하기 위한 인터페이스.
    int update(int index, int newValue){
        return update(index, newValue,1,0,n-1);
    }

};