
import java.io.*;
import java.util.*;
import java.lang.Math;

class dquery{

    static int[] arr;
    static int[] counter = new int[3000001];
    static int currentAnswer = 0;
    
    public static void main(String[] args) throws IOException{

        Scan reader = new Scan();
        
        // BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int n = reader.scanInt();
        // int n = Integer.parseInt(in.readLine());
        int block = (int)Math.sqrt(n);

        arr = new int[n];
        // String[] line = in.readLine().split(" ");
        for(int i=0;i<n;i++){
            arr[i] = reader.scanInt();
            // arr[i] = Integer.parseInt(line[i]);
        }

        int q = reader.scanInt();
        // int q = Integer.parseInt(in.readLine());
        Query[] queries = new Query[q];
        for(int i=0;i<q;i++){
            // String[] temp = in.readLine().split(" ");

            Query temp2 = new Query();
            // temp2.L = Integer.parseInt(temp[0]);
            // temp2.R = Integer.parseInt(temp[1]);

            temp2.L = reader.scanInt();
            temp2.R = reader.scanInt();
            
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

    static class Query{
        int L;
        int R;
        int I;
    }

    static class Scan
    {

        private byte[] buf = new byte[1024];

        private int total;
        private int index;
        private InputStream in;

        public Scan()
        {
            in = System.in;
        }

        public int scan() throws IOException
        {

            if(total < 0)
                throw new InputMismatchException();

            if(index >= total)
            {
                index = 0;
                total = in.read(buf);
                if(total <= 0)
                    return -1;
            }

            return buf[index++];
        }


        public int scanInt() throws IOException
        {

            int integer = 0;

            int n = scan();

            while(isWhiteSpace(n))   /*  remove starting white spaces   */
                n = scan();

            int neg = 1;
            if(n == '-')
            {
                neg = -1;
                n = scan();
            }

            while(!isWhiteSpace(n))
            {

                if(n >= '0' && n <= '9')
                {
                    integer *= 10;
                    integer += n-'0';
                    n = scan();
                }
                else
                    throw new InputMismatchException();
            }

            return neg*integer;
        }


        public String scanString()throws IOException
        {
            StringBuilder sb = new StringBuilder();

            int n = scan();

            while(isWhiteSpace(n))
                n = scan();

            while(!isWhiteSpace(n))
            {
                sb.append((char)n);
                n = scan();
            }

            return sb.toString();
        }


        public double scanDouble()throws IOException
        {
            double doub=0;
            int n=scan();
            while(isWhiteSpace(n))
            n=scan();
            int neg=1;
            if(n=='-')
            {
                neg=-1;
                n=scan();
            }
            while(!isWhiteSpace(n)&& n != '.')
            {
                if(n>='0'&&n<='9')
                {
                    doub*=10;
                    doub+=n-'0';
                    n=scan();
                }
                else throw new InputMismatchException();
            }
            if(n=='.')
            {
                n=scan();
                double temp=1;
                while(!isWhiteSpace(n))
                {
                    if(n>='0'&&n<='9')
                    {
                        temp/=10;
                        doub+=(n-'0')*temp;
                        n=scan();
                    }
                    else throw new InputMismatchException();
                }
            }
            return doub*neg;
        }

        public boolean isWhiteSpace(int n)
        {
            if(n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1)
                return true;

            return false;
        }

        public void close()throws IOException
        {
            in.close();
        }
    }
}
