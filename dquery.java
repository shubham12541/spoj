
import java.io.*;
import java.util.*;
import java.lang.Math;

public class dquery{

    static int[] arr;
    static int[] counter = new int[3000001];
    static int currentAnswer = 0;
    
    public static void main(String[] args) throws IOException{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(in.readLine());
        int block = (int)Math.sqrt(n);

        arr = new int[n];
        String[] line = in.readLine().split(" ");
        for(int i=0;i<line.length;i++){
            arr[i] = Integer.parseInt(line[i]);
        }

        int q = Integer.parseInt(in.readLine());
        Query[] queries = new Query[q];
        for(int i=0;i<q;i++){
            String[] temp = in.readLine().split(" ");

            Query temp2 = new Query();
            temp2.L = Integer.parseInt(temp[0]);
            temp2.R = Integer.parseInt(temp[1]);
            
            temp2.I = i;

            temp2.L--;
            temp2.R--;
            queries[i] = temp2;
        }

        Arrays.sort(queries, new Comparator<Query>() {
            @Override
            public int compare(Query o1, Query o2) {
                if(o1.L/block != o2.L/block){
                    return Integer.compare(o1.L, o2.L);
                }

                return Integer.compare(o1.R, o2.R);
            }
        });


        int currentL = 0, currentR = 0;

        int[] answerArr = new int[q];

        for(int i=0;i<q;i++){
            Query temp = queries[i];

            while(currentL < temp.L){
                remove(currentL);
                currentL++;
            }

            while(currentL > temp.L){
                add(currentL-1);
                currentL--;
            }

            while(currentR <= temp.R){
                add(currentR);
                currentR++;
            }

            while(currentR > temp.R + 1){
                remove(currentR-1);
                currentR--;
            }

            answerArr[temp.I] = currentAnswer;
        }

        for(int i=0;i<q;i++){
            System.out.println(answerArr[i]);
        }
        

    }


    static void add(int position){
        counter[arr[position]]++;

        if(counter[arr[position]] == 1){
            currentAnswer++;
        }
    }

    static void remove(int position){
        counter[arr[position]]--;
        
        if(counter[arr[position]] == 0){
            currentAnswer--;
        }
    }

    private static class Query{
        int L;
        int R;
        int I;
    }
}
