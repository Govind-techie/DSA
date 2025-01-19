    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    for(int st = 0 ; st < n ; st++){
        for(int end = st ; end < n ; end++){
            for(int i = st ; i <= end ; i++)
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    return 0;
}