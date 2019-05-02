%% Performance of simple implementations of all loop orderings
%% This Live Script
% This Live Script helps you again visualize the performance of the very simple 
% implementation of matrix-matrix multiplication from Week 1.  Make sure that 
% you uploaded the various data files from that week to MATLAB Online, in director 
% Assignments/Week1/C/data/.  This Live Script will copy them to Assignments/Week2/C/data/ 
% and will then use them to create a graph.  
% 
% You may want to also, optionally, execute 'make JPI' in Assignments/Week2/C/, 
% which collects data for the fasted loop ordering, JPI, but for larger problem 
% sizes (up to m=n=k=1500).  If you do not do this, be sure to uncomment the copying 
% of that same file from Week1!!!!

system( 'cp ../../../Week1/C/data/output_IJP.m .' );
system( 'cp ../../../Week1/C/data/output_IPJ.m .' );
system( 'cp ../../../Week1/C/data/output_JIP.m .' );
% system( 'cp ../../../Week1/C/data/output_JPI.m .' );   % uncomment me out if you don't rerun 'make JPI' in Week2/C
system( 'cp ../../../Week1/C/data/output_PIJ.m .' );
system( 'cp ../../../Week1/C/data/output_PJI.m .' )

% load plot colors
my_plot_colors;

% Create figure
figure1 = figure('Name','GFLOPS');

% Create axes, labels, legends.  In future routines for plotting performance, 
% the next few lines will be hidden in the script.
axes2 = axes('Parent',figure1);
hold(axes2,'on');
ylabel( 'GFLOPS', 'FontName', 'Helvetica Neue' );
xlabel( 'matrix dimension m=n=k', 'FontName', 'Helvetica Neue' );
box(axes2,'on');
set( axes2, 'FontName', 'Helvetica Neue', 'FontSize', 18);
             
% Plot time data for IJP  
output_IJP   % load data for IJP ordering
assert( max(abs(data(:,6))) < 1.0e-10, ...
    'Hmmm, better check if there is an accuracy problem');
plot( data(:,1), data(:,5), 'DisplayName', 'IJP', 'MarkerSize', 8, 'LineWidth', 2, ...
      'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 2,: ) );

% Plot time data for IPJ  (to plot change "0" to "1")
if ( 1 ) 
  output_IPJ   
  assert( max(abs(data(:,6))) < 1.0e-10, ...
      'Hmmm, better check if there is an accuracy problem');
  plot( data(:,1), data(:,5), 'DisplayName', 'IPJ', 'MarkerSize', 8, 'LineWidth', 2, ...
        'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 3,: ) );
end

% Plot time data for JIP  (to plot change "0" to "1")
if ( 1 ) 
  output_JIP   
  assert( max(abs(data(:,6))) < 1.0e-10, ...
      'Hmmm, better check if there is an accuracy problem');
  plot( data(:,1), data(:,5), 'DisplayName', 'JIP', 'MarkerSize', 8, 'LineWidth', 2, ...
        'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 4,: ) );
end

% Plot time data for PIJ  (to plot change "0" to "1")
if ( 1 ) 
  output_PIJ   
  assert( max(abs(data(:,6))) < 1.0e-10, ...
      'Hmmm, better check if there is an accuracy problem');
  plot( data(:,1), data(:,5), 'DisplayName', 'PIJ', 'MarkerSize', 8, 'LineWidth', 2, ...
        'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 6,: ) );
end

% Plot time data for PJI  (to plot change "0" to "1")
if ( 1 ) 
  output_PJI   
  assert( max(abs(data(:,6))) < 1.0e-10, ...
      'Hmmm, better check if there is an accuracy problem');
  plot( data(:,1), data(:,5), 'DisplayName', 'PJI', 'MarkerSize', 8, 'LineWidth', 2, ...
        'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 7,: ) );
end

% Plot time data for JPI  (to plot change "0" to "1")
if ( 1 ) 
  output_JPI   
  assert( max(abs(data(:,6))) < 1.0e-10, ...
      'Hmmm, better check if there is an accuracy problem');
  plot( data(:,1), data(:,5), 'DisplayName', 'JPI', 'MarkerSize', 8, 'LineWidth', 2, ...
        'Marker', 'o', 'LineStyle', '-.', 'Color', plot_colors( 5,: ) );
end

% Optionally show the reference implementation performance data
if ( 0 )
  plot( data(:,1), data(:,3), 'MarkerSize', 8, 'LineWidth', 1, ...
        'LineStyle', '-', 'DisplayName', 'Ref', 'Color', plot_colors( 1,: ) );
end

% Adjust the x-axis and y-axis range to start at 0
v = axis;                   % extract the current ranges
axis( [ 0 v(2) 0 v(4) ] )   % start the x axis and y axis at zero

% Optionally change the top of the graph to capture the theoretical peak
if ( 0 )
    turbo_clock_rate = 4.3;
    flops_per_cycle = 16;
    peak_gflops = turbo_clock_rate * flops_per_cycle;

    axis( [ 0 v(2) 0 peak_gflops ] )  
end

legend2 = legend( axes2, 'show' );
set( legend2, 'Location', 'east', 'FontSize', 18) ;

% Uncomment if you want to create a pdf for the graph
print( 'Plot_All_Orderings.png', '-dpng' );
%%