import { Component, OnInit } from '@angular/core';
import { RobotArmService } from '../robot-arm.service';
import { Axis } from './axis';
import { AXES } from './mock-axes';

@Component({
  selector: 'app-axes',
  templateUrl: './axes.component.html',
  styleUrls: ['./axes.component.css']
})
export class AxesComponent implements OnInit {

  axes: Axis[] = [];
  selectedAxis?: Axis;

  constructor(private robotArmService: RobotArmService) { }

  ngOnInit(): void {
    this.getAxes();
  }

  onSelect(axis: Axis): void {
    this.selectedAxis = axis;
  }

  getAxes(): void{
    this.robotArmService.getAxes()
              .subscribe(axes => this.axes = axes);
  }

}
