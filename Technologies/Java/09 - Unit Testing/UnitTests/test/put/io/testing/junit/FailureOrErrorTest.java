package put.io.testing.junit;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class FailureOrErrorTest {
    private Calculator calculator;

    @BeforeEach
    void beforeEach(){
        calculator = new Calculator();
    }

    @Test
    void test1(){
        //given
        int a = 10;
        int b = 20;
        //when
        int result = calculator.addPositiveNumbers(a,b);
        //then
        Assertions.assertEquals(0, result);
    }

    @Test
    void test2(){
        //given
        int a = 10;
        int b = -20;
        //when
        int result = calculator.addPositiveNumbers(a,b);
        //then
        Assertions.assertEquals(0, result);
    }

    //Question 4.1
    //test1 as a failure, test2 as an error

    @Test
    void test3(){

        try{
            Assertions.assertEquals(false, true);
        }catch(Throwable e){
            e.printStackTrace();
        }
    }
}

