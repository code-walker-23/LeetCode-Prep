class Solution {
    public int majorityElement(int[] nums) {
        // 1. consider your majority element as +ve and other as -ve
        // 2. If majority exist then +ve will more than the -ve
        // 3. The +ve can be together or in some portion throughout the array like +++--++ 
        // 4. At the end your ele variable end up with taking majority element with count > 0
        // 5. If we are not guaranteed that majority element exist or not so it doesn't mean that count > 0 so majority will exist then in that case you have to frq of ele variable then check > [n/2]
        int count = 1;
        int ele = nums[0];

        for(int i = 1; i < nums.length; i++){
            if(count == 0){
                ele = nums[i];
                count = 1;
            }else if(ele == nums[i])count++;
            else count--;
        }

        return ele;
    }
}