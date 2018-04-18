using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Chapter18Ex10
{
    public class Quicksort
    {
        //Class member variable(s)
        private int[] arr;

        //Determines if quicksort needs to be done
        public void Sort(int low, int high)
        {
            if(low < high)
            {
                int part = partition(arr, low, high);

                //Prints the array after each pass
                Console.Write("Array after this pass: ");
                for(int m = 0; m < arr.Length; m++)
                {
                    Console.Write("{0} ", arr[m]);
                }
                Console.WriteLine();

                //Recursive call to Sort for the two subarrays
                Sort(low, part-1);
                Sort(part+1, high);
            }   
        }
        //Partitions and sorts the array
        private int partition(int[] array, int lo, int hi)
        {
            //Swaps the first element and the middle element in the array
            int tmp = arr[(lo + hi) / 2];
            array[(lo+hi)/2] = array[lo];
            array[lo] = tmp;

            //Sets pivot and pivot index
            int pivot = array[lo];
            int pivIndex = lo;
            Console.WriteLine("Pivot: {0}", pivot);

            //Goes through each value in the array from the left
            for(int j = lo; j <= hi; j++)
            {
                //Determines if the value at index j is less than the pivot
                if(array[j] < pivot)
                {
                    //Increments pivIndex and swaps the two values
                    pivIndex++;
                    int temp = array[j];
                    array[j] = array[pivIndex];
                    array[pivIndex] = temp;
                }
                
            }
            //Swaps the first element and the pivot
            int te = array[lo];
            array[lo] = array[pivIndex];
            array[pivIndex] = te;

            Console.WriteLine();

            //Returns the pivot index
            return pivIndex;
        }
        
        //Constructor
        public Quicksort(int[] a)
        {
            arr = a;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //Variables
            int[] nums = new int[20];
            Random r = new Random();

            //Puts random values in the array
            for(int i = 0; i < nums.Length; i++)
            {
                nums[i] = r.Next(1, 99);
            }
            
            //Prints the unsorted array
            Console.Write("Unsorted: ");
            for (int k = 0; k < nums.Length; k++){
                Console.Write("{0} ", nums[k]);
            }
            Console.WriteLine();

            //Creates an object to Quicksort and calls the Sort function
            Quicksort q = new Quicksort(nums);
            q.Sort(0, nums.Length-1);

            //Prints the sorted array after 1 partition
            Console.Write("Sorted: ");
            for(int l = 0; l < nums.Length; l++)
            {
                Console.Write("{0} ", nums[l]);
            }

            Console.ReadKey();
        }
    }
}
/* This program differs from the problem in the textbook. The textbook states that the pivot should be the beginning element.
 * This program places the pivot at the middle element.
 */
