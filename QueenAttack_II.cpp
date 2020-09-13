// Hackerrank
int queensAttack(int n, int k, int x, int y, vector<vector<int>> obstacle) {
    // d11, d12, d21, d22 are for diagnoal distances. 
    // r1, r2 are for vertical distance. 
    // c1, c2 are for horizontal distance. 
    int d11, d12, d21, d22, r1, r2, c1, c2; 
    // d22  r2  d12         [n..........n]
    // c1   Q   c2                x,y
    // d11  r1  d21         [0..........n]
    
    // Initialise the distance to end of the board. 
    d11 = min(x-1, y-1);
    d12 = min(n-x, n-y);
    d21 = min(n-x, y-1);
    d22 = min(x-1, n-y);
    r1 = y-1;
    r2 = n-y;
    c1 = x-1;
    c2 = n-x;
    
    // For each obstacle find the minimum distance. 
    // If obstacle is present in any direction, 
    // distance will be updated.
    for(int i = 0; i < k ; i++){
        // r1
        if(obstacle[i][0] == x && obstacle[i][1] < y)   r1 = min(r1, y - obstacle[i][1]-1);
        // r2
        if(obstacle[i][0] == x && obstacle[i][1] > y)   r2 = min(r2, obstacle[i][1] - y -1);
        // c1
        if(obstacle[i][1] == y && obstacle[i][0] < x)   c1 = min(c1, x - obstacle[i][0]-1);
        // c2
        if(obstacle[i][1] == y && obstacle[i][0] > x)   c2 = min(c2, obstacle[i][0] - x -1);
        // d11
        if(x > obstacle[i][0] && y > obstacle[i][1] && x-obstacle[i][0] == y-obstacle[i][1])
            d11 = min(d11, x-obstacle[i][0]-1);                                                         
        // d12
        if(x < obstacle[i][0] && y < obstacle[i][1] && obstacle[i][0]-x == obstacle[i][1]-y)
            d12 = min(d12, obstacle[i][0]-x-1);                                                        
        // d21
        if(x < obstacle[i][0] && y > obstacle[i][1] && obstacle[i][0]-x == y-obstacle[i][1])
            d21 = min(d21, y-obstacle[i][1]-1);                                                             
        // d22
        if(x > obstacle[i][0] && y < obstacle[i][1] && x-obstacle[i][0] == obstacle[i][1]-y)
            d22 = min(d22, obstacle[i][1]-y-1);                                                     
    }   
    return d11 + d12 + d21 + d22 + r1 + r2 + c1 + c2;
}
