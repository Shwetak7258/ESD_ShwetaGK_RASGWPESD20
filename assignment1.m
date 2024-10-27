% Parameters
initial_velocity = 50;  % Initial velocity in m/s
launch_angle = 45;      % Launch angle in degrees
g = 9.81;               % Gravitational acceleration in m/s^2

% Convert angle to radians
theta = deg2rad(launch_angle);

% Time of flight
time_of_flight = (2 * initial_velocity * sin(theta)) / g;

% Maximum height
max_height = (initial_velocity^2 * (sin(theta))^2) / (2 * g);

% Range
range = (initial_velocity^2 * sin(2 * theta)) / g;

% Time vector for plotting
t = linspace(0, time_of_flight, 100);

% Trajectory equations
x = initial_velocity * cos(theta) * t;         % Horizontal distance
y = initial_velocity * sin(theta) * t - 0.5 * g * t.^2;  % Vertical distance

% Plotting
figure;
plot(x, y, 'b', 'LineWidth', 2);
hold on;
plot(range, 0, 'ro', 'MarkerFaceColor', 'r'); % Range point
plot(0, max_height, 'go', 'MarkerFaceColor', 'g'); % Max height point
xlabel('Distance (m)');
ylabel('Height (m)');
title('Projectile Trajectory');
legend('Trajectory', 'Range', 'Max Height');
grid on;

% Display results
disp(['Range: ', num2str(range), ' meters']);
disp(['Maximum Height: ', num2str(max_height), ' meters']);
disp(['Time of Flight: ', num2str(time_of_flight), ' seconds']);
