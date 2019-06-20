%% Impact of parallelizing packing on a multithreaded implementation of the third loop around the micro-kernel
% This Live Script helps you view the performance attained when parallelizing 
% the packing of blocks of A and/or blocks of B on a multithreaded implementation 
% of the second loop around the micro-kernel

% Close all existing figures. (This is important for the ".m" version of this file.)
close all

% import color scheme
my_plot_colors;
% 
% Set number of threads
% Some of the plots require knowledge about the number of threads that were 
% used.  Set that here (default is 4).

omp_num_threads = 4;

% View GFLOPS attained per thread

% Create figure
figure1 = figure('Name','GFLOPS/thread');

% Create axes, labels, legends.  In future routines for plotting performance, 
% the next few lines will be hidden in the script.
axes1 = axes('Parent',figure1);
hold(axes1,'on');
ylabel( 'GFLOPS/thread', 'FontName', 'Helvetica Neue' );
xlabel( 'matrix dimension m=n=k', 'FontName', 'Helvetica Neue' );
box(axes1,'on');
set( axes1, 'FontName', 'Helvetica Neue', 'FontSize', 18);         

% Import the data for the five loops without parallelizing (but with packing)
output_Five_Loops_Packed_8x6Kernel;

plot( data(:,1), data(:,5) , 'DisplayName', 'Single thread', 'MarkerSize', 8, 'LineWidth', 2, ...
      'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 1,: ) );

% Plot results for the reference implementation (single threaded)
plot( data(:,1), data(:,3) , ...
        'DisplayName', 'Ref single thread', 'MarkerSize', 8, 'LineWidth', 2, ...
          'Marker', '+', 'LineStyle', '-', 'Color', plot_colors( 7,: ) );

% Plot results for multithreaded Loop 3, without multithreading packing
output_MT_Loop3_8x6Kernel
plot( data(:,1), data(:,5)/omp_num_threads , 'DisplayName', 'MT Loop 3', 'MarkerSize', 8, 'LineWidth', 2, ...
          'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 4,: ) );

% Optionally, plot results for multithreaded Loop 3, with multithreading of
% the packing of row panels of B
if ( 1 ) 
    output_MT_Loop3_MT_PackB_8x6Kernel
    
    plot( data(:,1), data(:,5)/omp_num_threads , 'DisplayName', 'MT Loop 3 MT Pack B', 'MarkerSize', 8, 'LineWidth', 2, ...
          'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 5,: ) );
end

% Optionally, plot results for the reference implementation
if ( 1 )   
    plot( data(:,1), data(:,3)/omp_num_threads , 'DisplayName', 'Ref multithreaded', 'MarkerSize', 8, ...
        'LineWidth', 2, ...
        'Marker', '+', 'LineStyle', '-', 'Color', plot_colors( 8,: ) );
end
  
% Adjust the x-axis and y-axis range to start at 0
v = axis;                   % extract the current ranges
axis( [ 0 v(2) 0 v(4) ] )   % start the x axis and y axis at zero

legend1 = legend( axes1, 'show' );
set( legend1, 'Location', 'south', 'FontSize', 12) ;

% Uncomment if you want to create a png for the graph
print( 'Plot_MT_Loop3_MT_Pack.png', '-dpng' );