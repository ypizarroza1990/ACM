import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {
    static BigInteger fact[]=new BigInteger[55];
    static BigInteger bell[]=new BigInteger[55];
    static void F(){
        fact[0]=BigInteger.ONE;
        for(int i=1;i<=50;i++)
            fact[i]=BigInteger.valueOf(i).multiply(fact[i-1]);
    }
    static  BigInteger C(int i,int j){
        return fact[i].divide(fact[i-j].multiply(fact[j]));
    }
    public static void  Bell(){
        bell[0]=bell[1]=BigInteger.ONE;
         for(int i=1;i<=50;i++){
             BigInteger ans=BigInteger.ZERO;
             for(int j=0;j<=i;j++){
                 ans=ans.add(bell[j].multiply(C(i,j)));
             }
             bell[i+1]=ans;
         }      
    }
    public static void main(String[] args) throws IOException {
       BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
        F();
       Bell();
       String s=sc.readLine();
       while(!s.equals("0")){
           int t=Integer.parseInt(s);
           System.out.println(t+" "+bell[t]);
           s=sc.readLine();
    }
    }
    
}
