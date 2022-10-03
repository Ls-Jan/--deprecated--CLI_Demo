using System;
using System.Collections.Generic;


public class Program {
    static void Main(string[] args) {
        
        Controller ctr = new Controller();
        ctr.XJ_AddString("A");
        ctr.XJ_AddString("AB");
        ctr.XJ_AddString("ABC");
        ctr.XJ_AddString("1");
        ctr.XJ_AddString("12");
        ctr.XJ_AddString("123");

        char[] test = { 'A', 'B', 'C', '1', '2', '3' };
        for (uint t = 0; t < test.Length; ++t) {
            var rst = ctr.XJ_GetString(test[t]);
            Console.WriteLine("【" + test[t] + "】");
            foreach (var str in rst)
                Console.WriteLine(str);
            Console.WriteLine();
        }

        Console.Clear();
        var dict = ctr.XJ_GetDict();
        foreach (var x in dict) {
            Console.WriteLine("【" + x.Key + "】");
            foreach (var str in x.Value)
                Console.WriteLine(str);
            Console.WriteLine();
        }
        Console.ReadKey();

        return;
    }
}



