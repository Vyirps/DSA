
import java.util.Scanner;

public class Elevator {

    public static final int IDLE = 0;
    public static final int MOVING_UP = 1;
    public static final int MOVING_DOWN = 2;
    public static final int maxDestinations = 10;

    private int id;
    private int currentFloor;
    private int state;
    private int[] destinationFloors;
    private int destinationCount;

    public static void main(String[] args) {
        final int NUM_ELEVATORS = 2;
        final int MAX_DESTINATIONS = 10;
        final int MAX_REQUESTS = 20;
        final int NUM_FLOORS = 10;

        Elevator[] elevators = new Elevator[NUM_ELEVATORS];
        elevators[0] = new Elevator(1, 1, MAX_DESTINATIONS);
        elevators[1] = new Elevator(2, 8, MAX_DESTINATIONS);

        int[] allRequests = new int[MAX_REQUESTS];
        int requestCount = 0;
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter floor to call elevator (1-10) or '0' to exit: ");
            int floor = scanner.nextInt();
            if (floor == 0) {
                break;
            }
            if (floor < 1 || floor > NUM_FLOORS) {
                System.out.println("Invalid floor.");
                continue;
            }
            System.out.println("Request for floor " + floor + " received.");
            if (requestCount < MAX_REQUESTS) {
                allRequests[requestCount] = floor;
                requestCount++;
            } else {
                System.out.println("Request queue full.");
            }

            for (int r = 0; r < requestCount; r++) {
                int reqFloor = allRequests[r];
                Elevator bestElevator = selectBestElevator(elevators[0], elevators[1], reqFloor);
                System.out.println("Request for floor " + reqFloor + " assigned to elevator " + bestElevator.getId() + ".");
                bestElevator.addDestination(reqFloor);

                for (int k = r; k < requestCount - 1; k++) {
                    allRequests[k] = allRequests[k + 1];
                }
                requestCount--;
                r--;
            }

            for (Elevator e : elevators) {
                int prevFloor = e.getCurrentFloor();
                e.move();
                if (e.getCurrentFloor() != prevFloor) {
                    if (e.getDestinationCount() == 0 && e.getState() == Elevator.IDLE) {
                        System.out.println("Elevator " + e.getId() + " has arrived at floor " + e.getCurrentFloor() + ".");
                    }
                }
                System.out.println("Elevator " + e.getId() + " is at floor " + e.getCurrentFloor() + " and is currently " + e.getStateString() + ".");
            }
            System.out.println();
        }
        scanner.close();
    }

    public static Elevator selectBestElevator(Elevator e1, Elevator e2, int requestFloor) {
        if (e1.getState() == Elevator.IDLE && e2.getState() == Elevator.IDLE) {
            if (Math.abs(e1.getCurrentFloor() - requestFloor) <= Math.abs(e2.getCurrentFloor() - requestFloor)) {
                return e1;
            } else {
                return e2;
            }
        }
        if (isMovingToward(e1, requestFloor)) {
            return e1;
        }
        if (isMovingToward(e2, requestFloor)) {
            return e2;
        }
        if (Math.abs(e1.getCurrentFloor() - requestFloor) <= Math.abs(e2.getCurrentFloor() - requestFloor)) {
            return e1;
        } else {
            return e2;
        }
    }

    private static boolean isMovingToward(Elevator e, int floor) {
        if (e.getState() == Elevator.MOVING_UP && e.getCurrentFloor() < floor) {
            return true;
        }
        if (e.getState() == Elevator.MOVING_DOWN && e.getCurrentFloor() > floor) {
            return true;
        }
        return false;
    }

    public Elevator(int id, int startingFloor, int maxDestinations) {
        this.id = id;
        this.currentFloor = startingFloor;
        this.state = IDLE;
        this.destinationFloors = new int[maxDestinations];
    }

    public void addDestination(int floor) {
        if (destinationCount < maxDestinations) {
            boolean alrAdded = false;
            for (int i = 0; i < destinationCount; i++) {
                if (destinationFloors[i] == floor) {
                    alrAdded = true;
                    break;
                }
            }
            if (!alrAdded) {
                destinationFloors[destinationCount] = floor;
                destinationCount++;
                sortDestination();
            }
        }
    }

    public void move() {
        if (destinationCount == 0) {
            state = IDLE;
            return;
        }

        int target = destinationFloors[0];

        if (currentFloor < target) {
            currentFloor++;
            state = MOVING_UP;

        } else if (currentFloor > target) {
            currentFloor--;
            state = MOVING_DOWN;
        }

        if (currentFloor == target) {
            removeDestinationAtIndex(0);
            if (destinationCount == 0) {
                state = IDLE;

            } else if (currentFloor < destinationFloors[0]) {
                state = MOVING_UP;

            } else if (currentFloor > destinationFloors[0]) {
                state = MOVING_DOWN;
            }
        }

    }

    private void removeDestinationAtIndex(int index) {
        for (int i = 0; i < destinationCount - 1; i++) {
            destinationFloors[i] = destinationFloors[i + 1];
        }
        destinationCount--;
    }

    private void sortDestination() {
        for (int i = 0; i < destinationCount - 1; i++) {
            for (int j = 0; j < destinationCount - i - 1; j++) {
                if (state == MOVING_UP || state == IDLE) {
                    if (destinationFloors[j] > destinationFloors[j + 1]) {
                        int temp = destinationFloors[j];
                        destinationFloors[j] = destinationFloors[j + 1];
                        destinationFloors[j + 1] = temp;
                    }
                } else if (state == MOVING_DOWN) {
                    if (destinationFloors[j] < destinationFloors[j + 1]) {
                        int temp = destinationFloors[j];
                        destinationFloors[j] = destinationFloors[j + 1];
                        destinationFloors[j + 1] = temp;
                    }
                }
            }
        }
    }

    public int getId() {
        return id;
    }

    public int getCurrentFloor() {
        return currentFloor;
    }

    public int getState() {
        return state;
    }

    public int getDestinationCount() {
        return destinationCount;
    }

    public String getStateString() {
        switch (state) {
            case IDLE:
                return "IDLE";
            case MOVING_UP:
                return "UP";
            case MOVING_DOWN:
                return "DOWN";
            default:
                return "UNKNOWN";
        }
    }
}
