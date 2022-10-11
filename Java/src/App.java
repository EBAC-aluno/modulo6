public class App {
     
   public static void main(String[] args) {
 
      ICar car1 = new Ford();
      ICar car2 = new Chevrolet();
 
      ICar paintCar1 = new CarPainter(car1, "red");
      paintCar1.build();
       
      ICar paintCar2 = new CarPainter(car2, "gray");
      paintCar2.build();
       
   }
 
}
