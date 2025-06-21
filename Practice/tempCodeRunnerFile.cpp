int n=arr.size();
    int l=0;
    int r=n-1;

    //Skip from right
    while(r>0 and arr[r]>=arr[r-1])
        r--;
    
    int shortest=r;//Case-1: Remove all elements to the left of r
    while(l<r){
        while(r<n and arr[l]>arr[r])
            r++;
        
        shortest = min(shortest,r-l-1);//r-l-1: means removing both r & l elements

        l++;
        if(arr[l]<arr[l-1])
            break;
    }
    return shortest; 