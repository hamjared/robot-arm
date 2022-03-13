import { Component, OnInit, Input } from '@angular/core';
import { Axis } from '../axes/axis';
import { MessageService } from '../message.service';
import { RobotArmService } from '../robot-arm.service';
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-axis-detail',
  templateUrl: './axis-detail.component.html',
  styleUrls: ['./axis-detail.component.css']
})
export class AxisDetailComponent implements OnInit {

  @Input() axis?: Axis;

  angle: number = 0;



  constructor(private messageService: MessageService,
    private robotService: RobotArmService,
    private http: HttpClient) { }

  ngOnInit(): void {
  }

  setAngle(): void {
      this.messageService.add("Send clicked");
      this.http.post("http://10.0.0.81/rotateStepper", this.angle.toString()).subscribe();
      this.messageService.add("Request sent");
  }

}
