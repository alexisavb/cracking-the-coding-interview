public class Compression{
    public static void main(String arg[]){
        System.out.println(compression("AAAAAaaaa"));
        System.out.println(compression("aabcccccaaa"));
    }

    public static String compression(String str){
        StringBuilder strB = new StringBuilder();
        int count = 0;

        for(int i = 0; i < str.length(); i++){
            count++;
            if(i + 1 >= str.length() || str.charAt(i) != str.charAt(i + 1) ){
                strB.append(str.charAt(i));
                strB.append(count);
                count = 0; 
            }
        }

        return str.length() > strB.toString().length() ? strB.toString() : str;
    }
}

