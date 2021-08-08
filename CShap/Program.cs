using System;
using System.Collections.Generic;
namespace CShap
{
    class Program
    {
        static void Main(string[] args)
        {
            // string aFriend = "mingming";
            // Console.WriteLine($"Hello {aFriend}!");

            // int max = int.MaxValue;
            // int min = int.MinValue;
            // Console.WriteLine($"The range of integers is {min} to {max}");

            // double a = 5;
            // double b = 4;
            // double c = 2;
            // double d = (a + b) / c;
            // Console.WriteLine(d);

            // double a = 19;
            // double b = 23;
            // double c = 8;
            // double d = (a + b) / c;
            // Console.WriteLine(d);

            // double max = double.MaxValue;
            // double min = double.MinValue;
            // Console.WriteLine($"The range of double is {min} to {max}");


            // double third = 1.0 / 3.0;
            // Console.WriteLine(third);   

            // double d = 1.0 - 0.000000000000001;
            // Console.WriteLine(d);
            // if(Math.Abs(d - 1.0) <= 0.001) {
            //     Console.WriteLine("d == 1");
            // }

            // decimal min = decimal.MinValue;
            // decimal max = decimal.MaxValue;
            // Console.WriteLine($"The range of the decimal type is {min} to {max}");

            // double a = 1.0;
            // double b = 3.0;
            // Console.WriteLine(a / b);

            // decimal c = 1.0M;
            // decimal d = 3.0M;
            // Console.WriteLine(c / d);

            // double radius = 2.50;
            // double area = Math.PI * radius * radius;
            // Console.WriteLine(area);
            
            // for (int row = 1; row < 11; row++)
            // {
            //     for (char column = 'a'; column < 'k'; column++)
            //     {
            //         Console.WriteLine($"The cell is ({row}, {column})");
            //     }
            // }

            // int sum = 0;
            // for (int i = 1; i <= 20; i++)
            // {
            //     if(i % 3  == 0) {
            //         sum += i;
            //         Console.WriteLine(i);
            //     }
            // }
            // Console.WriteLine(sum);

            // var names = new List<string> {"name","lisa"};
            // names.Add("john");
            // names.Add("Wu");
            // names.Add("Jun");
            // names.Add("yang");
            // // names.Remove("lisa");
            // var idx = names.IndexOf("john");
            // Console.WriteLine(idx);
            // names.Sort();
            // foreach (var name in names)
            // {
            //     Console.WriteLine(name.ToUpper());
            // }


            var fibonacciNumbers = new List<int> {1, 1};
            var f1 = fibonacciNumbers[fibonacciNumbers.Count-1];
            var f2 = fibonacciNumbers[fibonacciNumbers.Count-2];
            for (int i = 0; i < 20-2; i++)
            {
                var f3 = f1 + f2;
                fibonacciNumbers.Add(f3);
                f1 = fibonacciNumbers[fibonacciNumbers.Count-1];
                f2 = fibonacciNumbers[fibonacciNumbers.Count-2];
            }
            Console.WriteLine(f1);
        }
    }
}
