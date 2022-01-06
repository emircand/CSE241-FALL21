import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Main {
    /**
     * driver code
     */
    public static void main(String[] args) {
        
        TestAllMethods();

    }

    /**
     * for sets s1 and s2, De Morgan says that !(s1 + s2) == !s1 ^ !s2
     * @param set1
     * @param set2
     * @return the proof of DeMorgan rule
     */
    public static boolean DeMorgan(DayofYearSet set1, DayofYearSet set2){
        DayofYearSet unionSet = new DayofYearSet();
        unionSet.union(set1, set2);
        DayofYearSet complementSet = new DayofYearSet();
        complementSet.complement(unionSet);

        DayofYearSet complementSet1 = new DayofYearSet();
        complementSet1.complement(set1);
        DayofYearSet complementSet2 = new DayofYearSet();
        complementSet2.complement(set2);

        DayofYearSet interSet = new DayofYearSet();
        interSet.intersect(complementSet1, complementSet2);

        if(complementSet.equals(interSet))
            return true;
        else return false;
    }

    /**
     * write DayofYearSet details to .txt file
     * @param set to be written
     */
    public static void SaveToFile(DayofYearSet set){
        try(FileWriter writer = new FileWriter("Union_Set.txt")){
            for(var i: set.getData()){
                writer.write(i.getDay() + " - " + i.getMonth() + " \n");
            }
            writer.close();
        } catch (IOException e) {}
    }

    /**
     * create an ArrayList filled with DayofYear references
     * @return ArrayList reference
     */
    public static ArrayList<DayofYearSet.DayofYear> CreateList(){
        Random rand = new Random();
        ArrayList<DayofYearSet.DayofYear> list = new ArrayList<>();

        for(int i = 0; i < 5 ; i++){
            int randDay = rand.nextInt(10) + 1;
            int randMonth = rand.nextInt(12) + 1;
            DayofYearSet.DayofYear date = new DayofYearSet.DayofYear(randDay, randMonth);
            list.add(date);
        }
        return list;
    }

    /**
     * create a DayofYearSet class reference
     * @return DayofYearSet reference
     */
    public static DayofYearSet CreateSet(){
        ArrayList<DayofYearSet.DayofYear> list;
        list = CreateList();
        DayofYearSet Set = new DayofYearSet(list);
        return Set;
    }

    /**
     * test all methods of the program
     */
    public static void TestAllMethods(){
        DayofYearSet.DayofYear date1 = new DayofYearSet.DayofYear(31, 12);
        System.out.println("number of alive DayofYear objects: " + date1.getCounter());
        DayofYearSet.DayofYear date2 = new DayofYearSet.DayofYear(28, 12);
        DayofYearSet.DayofYear date3 = new DayofYearSet.DayofYear(30, 12);
        DayofYearSet.DayofYear date4 = new DayofYearSet.DayofYear(29, 12);
        ArrayList<DayofYearSet.DayofYear> list = new ArrayList<>();
        list.add(date1);
        list.add(date1);
        list.add(date2);
        list.add(date3);
        list.add(date3);
        
        System.out.println("-set1-");
        DayofYearSet set1 = new DayofYearSet(list);
        System.out.println(set1);
        
        System.out.println("-set2-");
        DayofYearSet set2 = new DayofYearSet(list);
        System.out.println(set2);

        /*these sets were randomly created with helper methods.*/
        DayofYearSet set3 = CreateSet();
        System.out.println("-set3-");
        System.out.println(set3);
        DayofYearSet set4 = CreateSet();
        System.out.println("-set4-");
        System.out.println(set4);
        DayofYearSet set5 = CreateSet();
        System.out.println("-set5-");
        System.out.println(set5);
        DayofYearSet set6 = CreateSet();
        System.out.println("-set6-");
        System.out.println(set6);


        DayofYearSet set8 = new DayofYearSet();
        set8.complement(set1);
        System.out.println("complement of set1:");
        System.out.println(set8);
        
        DayofYearSet set7 = new DayofYearSet();
        set7.union(set3, set4);
        System.out.println("union of set3 - set4:");
        System.out.println(set7);

        DayofYearSet set9 = new DayofYearSet();
        set9.intersect(set1, set2);
        System.out.println("intersection of set1 - set2:");
        System.out.println(set9);

        if(set2.equals(set1))
            System.out.println("set1 and set2 are same sets\n--------------");

        DayofYearSet set10 = new DayofYearSet();
        set10.difference(set5, set6);
        System.out.println("difference of set5 from set6:");
        System.out.println(set10);

        if(DeMorgan(set1, set2))
            System.out.println("the program verify 'de morgan' rule for set1 - set2");
        else System.out.println("the program failed to verify 'de morgan' rule for set1 - set2");
        
        if(DeMorgan(set2, set3))
            System.out.println("the program verify 'de morgan' rule for set2 - set3");
        else System.out.println("the program failed to verify 'de morgan' rule for set2 - set3");

        if(DeMorgan(set3, set4))
            System.out.println("the program verify 'de morgan' rule for set3 - set4");
        else System.out.println("the program failed to verify 'de morgan' rule for set3 - set4");

        if(DeMorgan(set4, set5))
            System.out.println("the program verify 'de morgan' rule for set4 - set5");
        else System.out.println("the program failed to verify 'de morgan' rule for set4 - set5");

        if(DeMorgan(set5, set6))
            System.out.println("the program verify 'de morgan' rule for set5 - set6");
        else System.out.println("the program failed to verify 'de morgan' rule for set5 - set6");

        System.out.println("added new DayofYear reference: ");
        set1.add(date4);
        System.out.println(set1);
        set1.remove(date2);
        System.out.println(set1);

        System.out.println("number of alive DayofYear objects: " + date1.getCounter());

        SaveToFile(set7);
    }
}

