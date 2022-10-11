public class CarPainter extends CarDecorator {
    
    private String ink;

    public CarPainter(ICar car, String ink) {
          super(car);       
          this.ink = ink;
       }
 
       @Override
       public void build() {
          System.out.println("----------------------------------"); 
          car.build();        
          paintCar(ink);
       }
        
       private void paintCar(String ink){
          System.out.println("This car have been painted with " + ink + " color.");
          System.out.println("----------------------------------");
       }
}
