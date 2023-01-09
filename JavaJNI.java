public class JavaJNI {  // Save as HelloJNI.java
   static {
      System.loadLibrary("load"); // Load native library load.dll (Windows) or libload.so (Unixes)
                                   //  at runtime
                                   
   }
 
   // Declare an instance native method sayHello() which receives no parameter and returns void
   private native int JNI_callSumFunc(int n1, int n2);
   private native int JNI_callDiff(int n1, int n2);
   private native int JNI_callProdFunc(int n1, int n2);
   private native int JNI_callDivFunc(int n1, int n2);
 
   // Test Driver
   public static void main(String[] args) {
      System.out.println("Arithmetic Operations");
      //The functions are from C# with C language acting as a bridge
      System.out.println("The value of sum obtained in java code: "+new JavaJNI().JNI_callSumFunc(100, 20));  // Create an instance and invoke the native method
      System.out.println("The value of Difference obtained in java code: "+new JavaJNI().JNI_callDiff(20, 7)); 
      System.out.println("The value of Product obtained in java code: "+new JavaJNI().JNI_callProdFunc(10, 5)); 
      System.out.println("The value of Division obtained in java code: "+new JavaJNI().JNI_callDivFunc(1135, 5)); 
   }
}
