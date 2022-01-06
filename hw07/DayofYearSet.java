package emircand;
import java.util.ArrayList;

/**
 * DayofYearSet is a Java class to represent a set of DayOfYear objects.
 * @author Emircan Demirel
 * @since 2022-01-01
 */
public class DayofYearSet
{
    /**
     * static inner class of DayofYearSet class
     */
    public static class DayofYear{
        private int Day;
        private int Month;
        private static int counter;

        /**DayofYear class default constructor*/
        DayofYear(){
            Day = 1;
            Month = 1;
            counter++;
        }

        /**
         * DayofYear class constructor
         * @param day   initialized as private member Day for class
         * @param month initialized as private member Month for class
         */
        DayofYear(int day, int month){
        	Day = day;
        	Month = month;
        	testDate();
            counter++;
        }

        /**
         * @override equals method for DayofYear class 
         * @param obj an object to compare with this object
         * @return  if two objects are same return true; else return false
         */
        public boolean equals(DayofYear obj) {
            if(this.Day == obj.Day && this.Month == obj.Month)
                return true;
            else return false;
        }

        /**
         * getter Day value of the DayofYear class object
         * @return private 'Day' member of class
         */
        public int getDay(){
            return Day;
        }

        /**
         * getter for counter of the alive DayofYear class objects
         * @return number of alive objects
         */
        public int getCounter(){
            return counter;
        }

        /**
         * getter Month value of the DayofYear class object
         * @return private 'Month' member of class
         */
        public int getMonth(){
            return Month;
        }

        /**
         * test the validity of the month and day value for created object.
         * if date is invalid, terminate the program
         */
        private void testDate(){
            if(Day < 1 || Day > 31){
                System.out.println("invalid day value... exiting");
                System.exit(0);
            }
            else if(Month < 1 || Month > 12){
                System.out.println("invalid month value... exiting");
                System.exit(0);
            }

            if(Day > 28 && Month == 2){
                System.out.println("impossible date... exiting");
                System.exit(0);
            }
            else if(Day > 30 && (Month == 4 || Month == 6 || Month == 9 || Month == 11)){
                System.out.println("impossible date... exiting");
                System.exit(0);
            }
            else if(Day > 31 && (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)){
                System.out.println("impossible date... exiting");
                System.exit(0);
            }
        }

        /*Overridden toString method for DayofYear references*/
		public String toString(){
            return "month: " + Month + " day: " + Day;
        }
    }

    /**private DayofYear array variable, named as data, of DayofYearSet class*/
    private DayofYear[] data;

    /**DayofYearSet class default constructor*/
    DayofYearSet(){
        data = new DayofYear[0];
    }

    /**
     * DayofYearSet class constructor
     * @param arr This arraylist containing
     *            DayofYear objects which will 
     *            be added to the DayofYearSet 
     *            class' private data member 
     */
    DayofYearSet(ArrayList<DayofYear> arr){
        data = new DayofYear[arr.size()];
        int j=0;
        int counter = data.length;
        for(var index: arr){
            boolean flag = true;
            for(int i = 0; i < j; i++)
                if(index.equals(data[i])) flag = false;
            
            if(flag)
                data[j++] = index;
            else counter--;
        }

        if(counter != data.length){
            DayofYear[] temp = new DayofYear[j];
            for(int i = 0; i < j; i++)
                temp[i] = data[i];
                
            data = temp;
        }
            
    }

    /**
     * add new DayofYear object to DayofYearSet 
     * @param obj DayofYear reference
     */
    public void add(DayofYear obj){
        DayofYear[] temp = new DayofYear[size()+1];
        int j = 0;
        boolean flag = true;
        for(var i : data){
            if(i == null) break;
            else if(i.equals(obj)){
                System.out.println(obj + " has already added to set\n----------------");
                flag = false;
                break;
            }
            else
                temp[j++] = i;
        }
        if(flag){
            temp[j] = obj;
            data = temp;
            //System.out.println(obj + " succesfully added to set\n----------------");
        }
    }

    /**
     * Complement operation for the given set
     * @param obj1  DayofYearSet object 
     * @return      365 days except which 
     *              included in DayofYearSet  
     */
    public DayofYearSet complement(DayofYearSet obj1){
        int dayValue = 1, monthValue = 1; 
        for(int i = 0; i < 365; i++){
            boolean flag = true;
            for(var index : obj1.getData()){
                if(index.getDay() == dayValue && index.getMonth() == monthValue){
                    flag = false;
                }
            }
            if(flag == true){
                DayofYearSet.DayofYear newObj = new DayofYearSet.DayofYear(dayValue, monthValue);
                this.add(newObj);
            }
            if(dayValue == 28 && monthValue == 2){
                monthValue++;
                dayValue = 1;
            }
            else if(dayValue == 30 && (monthValue == 4 || monthValue == 6 || monthValue == 9 || monthValue == 11) ){
                monthValue++;
                dayValue = 1;
            }
            else if(dayValue == 31 && (monthValue == 1 || monthValue == 3 || monthValue == 5 || monthValue == 7 || monthValue == 8 || monthValue == 10) ){
                monthValue++;
                dayValue = 1;
            }
            else dayValue++;
        }


        return this;
    }

    /**
     * Difference operation for the given set
     * @param obj1 take all elements of obj1
     *             then compare them
     * @param obj2 compatible set of obj1
     * @return     set of all elements of obj1
     *             that are not elements of obj2
     */
    public DayofYearSet difference(DayofYearSet obj1, DayofYearSet obj2){
        for(var i : obj1.getData()){
            boolean flag = false;
            for(var j : obj2.getData()){
                if(i == null)
                    break;
                if(i.equals(j))
                    flag = true;
            }
            if(flag != true && i != null)
                this.add(i);
        }
        return this;
    }

    /** @override equals method for DayofYearSet references*/
    public boolean equals(DayofYearSet obj) {
        boolean flag = false;
        if(this.size() == obj.size())
        {
            for(var i : this.data){
                flag = false;
                for(var j : obj.data)
                    if(i.equals(j)) flag = true;
                
                    if (flag == false) break;
            }
                
        }
        return flag;
    }

    /**
     * getter for private data member of DayofYearSet
     * @return  data array
     */
    public DayofYear[] getData(){
        return data;
    }

    /**
     * Intersection operation for the given set
     * @param obj1 take all elements of obj1
     *             then compare them
     * @param obj2 compatible set of obj1
     * @return     set of all elements of obj1
     *             that are also elements of obj2
     */
    public DayofYearSet intersect(DayofYearSet obj1, DayofYearSet obj2){
        for(var i : obj1.getData()){
            boolean flag = false;
            for(var j : obj2.getData()){
                if(i == null)
                    break;
                if(i.equals(j))
                    flag = true;
            }
            if(flag == true && i != null)
                this.add(i);
        }
        return this;
    }

    /**
     * delete a DayofYear object from DayofYearSet 
     * @param obj DayofYear reference
     */
    public void remove(DayofYear obj){
        DayofYear[] temp = new DayofYear[this.size()-1];
        int j = 0;
        for(var i: this.getData()){
            if(i.equals(obj))
                System.out.println(obj + " removed from the set\n----------------");
            else
                temp[j++] = i;
        }
        data = new DayofYear[j];
        int k=0;
        for(var index: temp)
            data[k++] = index;
    }

    /**
     * method which gives size of DayofYearSet
     * @return data.length as size of the set
     */
    public int size(){
        return this.getData().length;
    }

    /** @override toString method for DayofYearSet references*/
	public String toString(){
        for(var i: this.getData())
                System.out.println(i);
        return "size of set: " + size() + "\n----------------";
    }

    /**
     * Union operation for the given set
     * @param obj1 take all elements of obj1
     *             then compare them
     * @param obj2 compatible set of obj1
     * @return     union set of obj1 and obj2 sets
     */
    public DayofYearSet union(DayofYearSet obj1, DayofYearSet obj2){
        DayofYearSet tempDiffObj1 = new DayofYearSet();
        tempDiffObj1.difference(obj1, obj2);
        DayofYearSet tempDiffObj2 = new DayofYearSet();
        tempDiffObj2.difference(obj2, obj1);
        DayofYearSet tempInterObj = new DayofYearSet();
        tempInterObj.intersect(obj1, obj2);

        for (var i: tempDiffObj1.getData())
            this.add(i);
        for (var i: tempDiffObj2.getData())
            this.add(i);
        for (var i: tempInterObj.getData())
            this.add(i);
        return this;
    }
}