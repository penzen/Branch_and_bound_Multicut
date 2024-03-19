# Branch_and_bound_Multicut
There are diffrent test data provided in txt format, plug in the name of text file to test the data 
vector<vector<int>> myGraphData = readGraphData("graph_cars.txt"); 
After specify the file please update the start node  at the graph 
graph = depth_search(adj, graph, 20, 0, 0);
Please start with the provided test data.

To test the diffrent bounds remove the comment symbole and comment the other bound 
For the bounder 
           ======================== Join ===========================
           //one.bo = frcut(adj,one.pcut); 
         //   one.bo = nd_bounder(one.jyon, j, one.pcut);
           one.bo = bounder(adj,one.pcut);   <---------------------  use this
          one = depth_search(one.jyon, one, j, bound, lower);
          lower = one.bo;  <------------------------------------------------- use this
          // lower = bounder(one.bd_ref,one.pcut);
          ========================== CUT ============================
          ken.bo = bounder(adj,ken.pcut);  <-----------------------------------------use this
          //ken.bo = nd_bounder(ken.part, ref.second, ken.pcut);
           ken = depth_search(ken.part, ken, ref.second, bound, lower);

For the frcut  
          ======================== Join ===========================
           one.bo = frcut(adj,one.pcut);    <--------------------- use this
         //   one.bo = nd_bounder(one.jyon, j, one.pcut);
        //   one.bo = bounder(adj,one.pcut);
          one = depth_search(one.jyon, one, j, bound, lower);
        //lower = one.bo; 
         lower = bounder(one.bd_ref,one.pcut);  <------------------------------------------------- use this 
         ========================== CUT ============================
          ken.bo = bounder(adj,ken.pcut);  <----------------------------------------- use this 
          //ken.bo = nd_bounder(ken.part, ref.second, ken.pcut);
           ken = depth_search(ken.part, ken, ref.second, bound, lower);

For the nd_bounder 
    ======================== Join ===========================
       //   one.bo = frcut(adj,one.pcut);    
            one.bo = nd_bounder(one.jyon, j, one.pcut);  <--------------------- use this
        //  one.bo = bounder(adj,one.pcut);
          one = depth_search(one.jyon, one, j, bound, lower);
          lower = one.bo; <------------------------------------------------- use this 
        //lower = bounder(one.bd_ref,one.pcut);  
   ========================== CUT ============================
         //ken.bo = bounder(adj,ken.pcut); 
           ken.bo = nd_bounder(ken.part, ref.second, ken.pcut);  <----------------------------------------- use this 
           ken = depth_search(ken.part, ken, ref.second, bound, lower);







           
