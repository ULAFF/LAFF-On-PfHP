%% Aggregate performance
% This Live Script helps you view the aggregate performance attained when different 
% loops in the "Five loops around the micro-kernel" are parallelized.  

% Close all existing figures. (This is important for the ".m" version of this file.)
close all

% import color scheme
my_plot_colors;
% 
% View GFLOPS attained 

% Create figure
figure1 = figure('Name','GFLOPS');

% Create axes, labels, legends.  In future routines for plotting performance, 
% the next few lines will be hidden in the script.
axes1 = axes('Parent',figure1);
hold(axes1,'on');
ylabel( 'GFLOPS', 'FontName', 'Helvetica Neue' );
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
  
% Optionally, plot results for multithreaded Loop 1
if ( 1 ) 
    output_MT_Loop1_8x6Kernel
    plot( data(:,1), data(:,5), 'DisplayName', 'MT Loop 1', 'MarkerSize', 8, 'LineWidth', 2, ...
          'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 2,: ) );
end

% Optionally, plot results for multithreaded Loop 2
if ( 1 ) 
    output_MT_Loop2_8x6Kernel
    plot( data(:,1), data(:,5), 'DisplayName', 'MT Loop 2', 'MarkerSize', 8, 'LineWidth', 2, ...
          'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 3,: ) );
end

% Optionally, plot results for multithreaded Loop 3
if ( 1 ) 
    output_MT_Loop3_8x6Kernel
    plot( data(:,1), data(:,5), 'DisplayName', 'MT Loop 3', 'MarkerSize', 8, 'LineWidth', 2, ...
          'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 4,: ) );
end

% Optionally, plot results for multithreaded Loop 4
if ( 0 ) 
    output_MT_Loop4_8x6Kernel
    plot( data(:,1), data(:,5), 'DisplayName', 'MT Loop 4', 'MarkerSize', 8, 'LineWidth', 2, ...
          'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 5,: ) );
end

% Optionally, plot results for multithreaded Loop 5
if ( 1 ) 
    output_MT_Loop5_8x6Kernel
    plot( data(:,1), data(:,5), 'DisplayName', 'MT Loop 5', 'MarkerSize', 8, 'LineWidth', 2, ...
          'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 6,: ) );
end

% Optionally, plot results for the reference implementation
if ( 1 )   
    plot( data(:,1), data(:,3), 'DisplayName', 'Ref multithreaded', 'MarkerSize', 8, ...
        'LineWidth', 2, ...
        'Marker', '+', 'LineStyle', '-', 'Color', plot_colors( 8,: ) );
end
  
% Adjust the x-axis and y-axis range to start at 0
v = axis;                   % extract the current ranges
axis( [ 0 v(2) 0 v(4) ] )   % start the x axis and y axis at zero

legend1 = legend( axes1, 'show' );
set( legend1, 'Location', 'south', 'FontSize', 12) ;

% Uncomment if you want to create a png for the graph
print( 'Plot_MT_Aggregate_GFLOPS_8x6.png', '-dpng' );