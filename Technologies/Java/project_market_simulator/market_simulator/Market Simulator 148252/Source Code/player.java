package com.mycompany.market_simulator;

import static java.lang.Math.abs;
import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *Player class
 * 
 * @author Bogna
 */
public class player implements Runnable{
    
    private int id;
    protected float budget;
    private int transactions_per_minute;
    private int bear;
    private int bull;
    private boolean stop;
    protected ArrayList<kapital> list_of_assets;
    private kapital observed_asset;
    private Random rnd;
    
    /**
     * Player constructor
     * 
     * @param t_p_m     transactions per minute
     * @param p_bear    bear in bear/bull ratio
     * @param p_bull    bull in bear/bull ratio
     * @param p_stop    stop is true, when the user clicks the stop-button, false if the user click the stop-button again
     * @param p_id      identifier of the player
     * @param p_budget  budget of the player
     * @param o_asset   asset which player may buy
     */
    public player(int t_p_m, int p_bear, int p_bull, boolean p_stop, int p_id, float p_budget, kapital o_asset){
        id = p_id;
        budget = p_budget;
        transactions_per_minute = t_p_m;
        bear = p_bear;
        bull = p_bull;
        stop = p_stop;
        list_of_assets = new ArrayList<kapital>();
        observed_asset = o_asset;
        rnd = new Random();
    }
    
    /**
     * Run the thread which buys and sells assets
     */
    public void run(){
        
        while(true){

            while(!stop){
                int willing_to_buy = abs(rnd.nextInt()%10);
                
                if(willing_to_buy < bear){  
                    if(observed_asset.getCurrent_price() <= budget){
                        this.buy_asset(observed_asset);
                    }                   
                }else{
                    if(list_of_assets.size()>0){
                        this.sell_asset();
                    }
                }  
                
                int time_to_next_transaction = 60/transactions_per_minute;
                
                try {
                    TimeUnit.SECONDS.sleep(time_to_next_transaction);
                } catch (InterruptedException ex) {
                    Logger.getLogger(player.class.getName()).log(Level.SEVERE, null, ex);
                }
                
            }
            
            try {
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException ex) {
                Logger.getLogger(player.class.getName()).log(Level.SEVERE, null, ex);
            }
            
        }
    }
    
    /**
     * Update transactions_per_minute by assigning the n
     * 
     * @param n value which will be assigned to the transaction_per_minute variable
     */
    public void update_trans_per_m(int n){
        transactions_per_minute = n;
    }
    
    /**
     * Updates bear and bull variables
     * 
     * @param n new value of the bear, 10-n is the new value of the bull
     */
    public void update_bear_bull_ratio(int n){
        bull = n;
        bear = 10-n;
    }
    
    /**
     * Update the stop
     * 
     * @param n if true, then stop is also true
     */
    public void update_stop(boolean n){
        stop = n;
    }
    
    /**
     * Update the asset which may be bought by the player
     * 
     * @param a asset
     */
    public void update_observed_asset(kapital a){
        observed_asset = a;
    }
    
    /**
     * Name getter
     * 
     * @return name 
     */
    public String getName(){
        return "name";
    }
    
    /**
     * Budget getter
     * 
     * @return budget
     */
    public float getBudget(){
        return budget;
    }
    
    /**
     * Size of the list getter
     * 
     * @return size of the list with assets which are bought by the Player
     */
    public int getAssetSize(){
        return list_of_assets.size();
    }
    
    /**
     * Name of the observed asset getter
     * 
     * @return name of the observed_asset
     */
    public String getAssetName(){
        String name = observed_asset.getName();
        return name;
    }
    
    /**
     * Buy the observed asset, update the budget and set new price for the asset
     * 
     * @param asset asset to buy
     */
    public synchronized void buy_asset(kapital asset){
        
        String a_name = asset.getName();
        float a_cost = asset.getCurrent_price();
        budget -= a_cost;
        list_of_assets.add(asset);
     
        System.out.println(id + " player bought " + a_name + ": " + a_cost);
        asset.change_current_price(abs(rnd.nextFloat() * 100));
    }
    
    /**
     * Sell the first asset from the list of assets, update budget and set new price for the asset
     */
    public synchronized void sell_asset(){
        kapital asset = list_of_assets.get(0);
        float a_cost = asset.getCurrent_price();
        String a_name = asset.getName();
        budget += a_cost;
        list_of_assets.remove(0);
        
        System.out.println(id + " player sold " + a_name + ": " + a_cost);
        asset.change_current_price(abs(rnd.nextFloat() * 100) * (-1));
    }
}
