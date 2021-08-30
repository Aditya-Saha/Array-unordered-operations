#include<stdio.h>
#include<stdlib.h>
int main(void)
{
 
 int task();//prototype of the function where the everything is performed

 task();//calling the function
  
 getchar();
 return (1);
}

//-------------------------------------------------------------------------------------------------------------------------
int menu(int *choice)//separate function to diplay the menu list to the user
{
 printf("\t\tThe menu of operations are listed below ");//showing menu

 printf("\n01.Display the content of the array with index number.\n02.Insert a given value.\n03.Insert a given value at any given index.\n04.Insert a given value before the maximum value of the array.\n05.Insert a given value after the minimum value of the array.\n06.Search a given value using linear search method.\n07.search Maximum_minimum values from the array.\n08.Search number of occurences of a given value from the array and show their   index numbers.\n\n09.Delete a given number.\n10.Delete second maximum value.\n11.Delete kth Minimum Value(without sorting).\n12.Remove all the repeated occurance of the value from the array.\n ");


 printf("\n\n Enter choice:");
 scanf("%d",&*choice);//taking choice of user as input
 return(1);
}
//----------------------------------------------------------------------------------------------------------------------------
int task()//separate function for task asked for
{
 int arr[100], noe , KEY, loc, pos, number_of_occurence, i , j, k , max , min, choice;//variable declaration
 //arr is the main array 
 
 char ch, control;//declaration of char type variables 
 
 control='y';//storing y initilally


 //prototype of the functions
 int menu();
 int display(int [],int );
 int insert_a_value(int [],int ,int *);
 int insert_at_index( int [],int ,int ,int *);
 int search_minimum_value(int [],int,int *,int *);
 int search_maximum_value(int [],int,int *,int *);
 int search_value(int [],int ,int *, int);
 int Number_of_occurence(int [],int ,int ,int *);
 int delete_a_value(int [],int ,int ,int *);
 int delete_2nd_max(int [] , int *);
 int delete_kth_min(int [] ,int *,int);
 int remove_repeated_occurence(int [],int *);


  while(1)
  {
   system("clear");
   menu(&choice);//calling function to show the list of menu    
   
   getchar();
   
   switch(choice)
   {
     case 01:printf("\nThe array is:\n");
     display(arr,noe);//calling function to display the array
     break;
     //------------------------------------------------------------------------
     case 02:printf("\nEnter the value you want to insert:");
     scanf("%d",&KEY);//taking input of value  we want to insert

     insert_a_value(arr, KEY, &noe);//calling function to insert value at the end

     printf("\nThe value is inserted...");
     break;
     //------------------------------------------------------------------------
     case 03:printf("\nEnter the value you want to insert:");
     scanf("%d",&KEY);//taking input of value  we want to insert

     printf("\nEnter the index where you want to insert the value:");
     scanf("%d",&loc);//taking input of the index where we will insert the given value
     
     insert_at_index( arr, KEY, loc, &noe);//calling function to insert value at the given index

     printf("\nThe value is inserted at %dth index...",loc);
     break;
     //------------------------------------------------------------------------
     case 04:printf("\nEnter the value you want to insert:");
     scanf("%d",&KEY);//taking input of value  we want to insert
     
     search_maximum_value( arr,noe,&max, &pos);//calling function to find the index of maximum number from the array
     
     insert_at_index( arr, KEY, pos, &noe);//calling function to insert value before the maximum value
     
     printf("\nThe value is inserted before the maximum value of the array...");
     break;
     //-----------------------------------------------------------------------
     case 05:printf("\nEnter the value you want to insert:");
     scanf("%d",&KEY);//taking input of value  we want to insert
     
     search_minimum_value( arr,noe,&min,&pos);//calling function to find the index of minimum number from the array

     loc=pos+1;//setting the index after the index of minimum value

     insert_at_index( arr, KEY, loc, &noe);//calling function to insert value after the minimum value 
  
     printf("\nThe value is inserted after the minimum value of the array...");
     break;
     //------------------------------------------------------------------------
     case 06:printf("\n\nEnter the value you want to search:");
     scanf("%d",&KEY);//taking input of value  we want to search
    
     search_value( arr, KEY, &loc, noe);//calling function to search the given value
     break;
     //-------------------------------------------------------------------------
     case 07:search_maximum_value( arr,noe,&max, &pos);//calling function to find the  maximum number from the array
     printf("\nThe maximum value is found at %dth index",pos);

     search_minimum_value( arr,noe,&min, &pos);//calling function to find the  minimum number from the array
     printf("\nThe minimum value is found at %dth index",pos);
     break;
     //--------------------------------------------------------------------------
     case 8:printf("Enter the value whose number of occurence you want to find in the array:");
     scanf("%d",&KEY);//taking input of value whose number of occurence you want to find
   
     printf("\n\nThe number of occurence of the given value are found at following index:");
     Number_of_occurence( arr,  KEY,noe, &number_of_occurence);
     
     
     printf("\n The number of occurence of the given value is %d",number_of_occurence);//printing number_of_occurence
     break;
     //------------------------------------------------------------------------------
     case 9:printf("\nEnter the value you want to delete:");
     scanf("%d",&KEY);//taking input of value  we want to delete
   
     search_value(arr, KEY, &loc, noe);//calling function to search the given value

     pos=loc+1;

     delete_a_value(arr, KEY, pos, &noe); //calling function to delete the value

     printf("\n\n The given value is deleted...");
     break;
     //------------------------------------------------------------------------------
     case 10:
     delete_2nd_max( arr, &noe);   //calling function to delete the second maximum value
    
     printf("\n\nThe 2nd maximum value is deleted...");
     break;
     //------------------------------------------------------------------------------
     case 11:printf("\n\nEnter the value of K for deleting Kth minimum value...:");
     scanf("%d",&k);//taking input of K for deleting Kth minimum value
       
     delete_kth_min( arr, &noe,k);//calling function to delete the Kth minimum value
     
     printf("\n\nThe Kth minimum value is deleted...");
     break;
     //------------------------------------------------------------------------------
     case 12:remove_repeated_occurence(arr ,&noe);//calling function to remove repeated occurence of values

     printf("The all repeated occurance of values are removed from the array....");
     
     break;
     //------------------------------------------------------------------------------ 
     default:
     printf("\nWrong choice .please read the menu  carefully.....\n");//displaying the error message
     exit(1);
     break;  
    }
    getchar();

    printf("\n\n press y to continue:");//asking user whether he wants to continue thwn to press y 

    control=getchar();   
    if(control!='y')//checking whether user pressed any other character other than y
    {
      break;//then break from the loop structure
    }

   }
  getchar();
  return(1);
}
      
//-----------------------------------------------------------------------------------------------------------------------------
int display(int arr[],int noe)//separate function to display array
{
 int i;//i stands for index number
 
 i=0;
 while(i<noe)
 {
  printf("\nThe content at index %d is %d",i,arr[i]);//printing the array element with its index number

  i=i+1;
 }

 return(1);
}
//------------------------------------------------------------------------------------------------------------------------------
int insert_a_value(int arr[],int key,int *noe)//separate function to insert value at the end 
{
 arr[*noe]=key;//inserting value at noe th index

 *noe=*noe+1;//incrementing number of element(noe) by  1
 
 return(1);
}
//------------------------------------------------------------------------------------------------------------------------------
int insert_at_index( int arr[],int key,int loc,int *noe)//separate function to insert value at the given index
{
 int last_index;//variable declaration
 
 last_index=*noe-1;//set the last_index to index of last element
 
 while(last_index>=loc)//loop to run till last_index is >=loc i.e the index where to insert
 {
   arr[last_index+1]=arr[last_index];//moving the elements towards right till the loc index

   last_index=last_index-1;//decrementing by 1
 }
 
 arr[loc]=key;//inserting the value at loc index

 *noe=*noe+1;//incrementing number of element(noe) by  1
 
 return(1);
}
//-----------------------------------------------------------------------------------------------------------------------------------
int search_minimum_value(int arr[],int noe,int *min,int *pos)//separate function to search minimumn value in the array
{
 int index;//variable declaration

 index=1; //initialising index to 1
 
 *min=arr[0];//storing first element in *min 
 *pos=0;
 
 while(index<noe)//loop to run till number of element(noe)
 {

   if(arr[index]<(*min))//comparing element if less then
   {

     *min=arr[index];//storing the element in *minProblem Statement: Write a Menu Driven program in C to Perform the following operations in an
unordered numerical array.
1. Display the content of the array with index number.
2. Insert
1. A given value.
2. A given value at any given index.
3. A given value before the maximum value of the array.
4. A given value after the minimum value of the array.
3. Search
1. A given value using Linear Search Method.
2. Maximum-Minimum values from the array.
3. Number of occurences of a given value from the array and show their index numbers.
4. Delete
1. A given value.
2. 2 nd Maximum Value.
3. K th Minimum Value(without sorting).
5. Remove all repeated occurance of the values from the array.

     *pos=index;//storing the index in *pos

     index=index+1;//incrementing index by 1
   }
    else 
   {
     index=index+1;//incrementing index by 1
   }

 }
 

 return(1);
}
//-----------------------------------------------------------------------------------------------------------------------------------
int search_maximum_value(int arr[],int noe,int *max,int *pos)//separate function to search minimumn value in the array
{
 int index;//variable declaration

 index=1; //initialising index to 1

 *max=arr[0];//storing first element in *max 
 *pos=0;
 
 while(index<noe)//loop to run till number of element(noe)
 {
   if(arr[index]>(*max))//comparing element if less then
   {

     *max=arr[index];//storing the element in *max

     *pos=index;//storing the index in *pos

     index=index+1;//incrementing index by 1
   }
    else 
   {
     index=index+1;//incrementing index by 1
   }

 }
 
 return(1);
}
//-----------------------------------------------------------------------------------------------------------------------------------
int search_value(int arr[],int key,int *loc,int noe)//separate function for search a particular value
{
 int index;//variable declaration
 
 index=0;//initialising index to 0

 while(index<noe)//loop to run till number of element(noe)
 {

   if(arr[index]==key)//checking if element is equal to key
   {

     *loc=index;//storing the index of found element in *loc

     break;
   }

   index=index+1;//incrementing index by 1
 }


 if(index>noe)//checking if index is greater than number of element(noe)
 {
  printf("Element not found within the array");
 }
 else
 {
  printf("Element found at  index %d ",*loc);
 }

 return(1);
}
//------------------------------------------------------------------------------------------------------------------------------------
int Number_of_occurence(int arr[],int key,int noe,int *number_of_occurence)//function to find number of occurence of a given value
{
 int index, i;//variable declaration
 
 index=0;//initialising index to 0
 i=0;//initialising i  to 0
 
 while(index<noe)//loop to run till number of element(noe)
 {
   if(arr[index]==key)//checking if element is equal to key
   {
     printf("%d,",index);//printing theier index number

     i=i+1;//incrementing i  by 1
   }

   index=index+1;//incrementing index by 1
 }

 
 *number_of_occurence=i;//storing i which is the number of occuremnce of value
 
 return(1);
}
//------------------------------------------------------------------------------------------------------------------------------------     
int delete_a_value(int arr[],int key,int pos,int *noe)//separate function to delete a given value
{
 int loc;//variable declaration

 loc=pos-1;
 
 while( loc<(*noe-1))//loop to run from loc (index of given value)
 {

   arr[loc]=arr[loc+1];//left shifting each element towards loc

   loc=loc+1;
 }
 *noe=*noe-1;//decrementing number of element(noe) by 1
 
 return(1);
}
//------------------------------------------------------------------------------------------------------------------------------------
int delete_2nd_max(int arr[],int *noe)//function to delete second maximum value
{
  int ARR[100], max, index, k, pos;//variable declaration
  
  index=0;//initialising index to 0
  while(index<*noe)
  {
   ARR[index]=arr[index];//copying element of arr to ARR indexwise
   index=index+1;
  }
  

  k=2;//initialising k to 2 s we have to finf second max element

  while(k!=0)//loop to run till k not equal to 0
  {
   search_maximum_value(ARR, *noe, &max,&pos);//calling function to search maximum in ARR array

   ARR[pos]=-99999;//storing a large negative number in that pos index

   k=k-1;//decrementing k by 1
  }

  delete_a_value(arr ,max,pos+1,&*noe);//calling function to delete value AT (pos+1) position

   
  return(1);
}
//-----------------------------------------------------------------------------------------------------------------------------------
int delete_kth_min(int arr[], int *noe,int k)//function to delete kth minimum value
{

  int ARR[100], min, index, pos;//variable declaration
  
  index=0;//initialising index to 0
  while(index<*noe)
  {
   ARR[index]=arr[index];//copying element of arr to ARR indexwise
   index=index+1;
  }
  

  while(k!=0)//loop to run till k not equal to 0
  {
   search_minimum_value(ARR, *noe, &min,&pos);//calling function to search minimum in ARR array

   ARR[pos]=99999;//storing a large positive number in that pos index

   k=k-1;//decrementing k by 1
  }
  printf("%d",pos);
  delete_a_value(arr ,min,pos+1,&*noe);//calling function to delete value AT (pos+1) position

   
 return(1);
}
//-------------------------------------------------------------------------------------------------------------------------------------
int remove_repeated_occurence(int arr[],int *noe)//function to remove all repeated occurence of values
{
 int i, j, pos;//variable declaration
 
 i=0;//initialising i to 0

 while(i<*noe)// loop to run till i is less than number of element (*noe)
 {
   j=i+1;//initialising j to index next to i

   while(j<*noe)// loop to run till j is less than number of element (*noe)
   {
     if(arr[i]==arr[j])//checking if element in ith index is equal to jth index element
     {
       delete_a_value(arr,arr[j],j+1,&*noe);//then calling function to delete that element in j th index
     }
     else
     {
       j=j+1;//incrementing j by 1
     }
   }
   i=i+1;//incrementing i by 1
 }
 
 return(1);
}
//-----------------------------------------------------------------------------------------------------------------------------------
