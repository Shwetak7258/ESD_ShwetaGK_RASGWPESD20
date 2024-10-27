% Parameters
num_points = 100;          % Number of random points
random_sequence = rand(1, num_points);  % Generate a sequence of random numbers

% Plotting
figure;
plot(random_sequence, '-o', 'LineWidth', 1.5, 'MarkerSize', 4, 'Color', [0.1 0.5 0.8]);
xlabel('Index');
ylabel('Random Value');
title('Random Number Sequence');
grid on;
