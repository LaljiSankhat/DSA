import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class MaximumMeetingsInARoom {
    private static class Meeting{
        int startTime;
        int finishTime;
        int meetingNumber;
        public String toString(){
            return startTime + " " + finishTime;
        }
    }
    private static class MeetingComparator implements Comparator<Meeting>{
        public int compare(Meeting m1,Meeting m2){
            if(m1.finishTime > m2.finishTime) return 1;
            else if (m1.finishTime < m2.finishTime) return -1;
            else return 0;
        }
    }
    public static void main(String[] args) {
        List<Integer> start = List.of(1, 3, 0, 5, 8, 5);
        List<Integer> finish = List.of(2, 4, 6, 7, 9, 9);
        List<Meeting> meetings = new ArrayList<>();
        for(int i = 0; i < start.size(); i++){
            Meeting m = new Meeting();
            m.startTime = start.get(i);
            m.finishTime = finish.get(i);
            m.meetingNumber = i + 1;
            meetings.add(m);
        }
        meetings.sort(new MeetingComparator());
        System.out.println(meetings);
        List<Integer> result = new ArrayList<>();
        result.add(meetings.get(0).meetingNumber);
        Meeting onGoingMeeting = meetings.get(0);
        for(int i = 1; i < meetings.size(); i++){
            Meeting currentMeeting = meetings.get(i);
            if(currentMeeting.startTime > onGoingMeeting.finishTime){
                result.add(currentMeeting.meetingNumber);
                onGoingMeeting = currentMeeting;
            }
        }
        System.out.println(result);
    }
}
